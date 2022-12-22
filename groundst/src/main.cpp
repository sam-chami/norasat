//
// Cansat groundstation TUI
// No license - Samuel M - IES Rio Nora
//

#include <ftxui/dom/elements.hpp>
#include <ftxui/screen/screen.hpp>
#include "ftxui/dom/node.hpp"
#include "ftxui/screen/color.hpp"

#include <stdio.h>
#include <iostream>
#include <chrono>
#include <thread>
#include <cmath>
#include <functional>
#include <vector>
#include <string.h>

#include <fcntl.h>
#include <errno.h>
#include <termios.h>
#include <unistd.h>


class Graph {
 public:
  std::vector<int> operator()(int width, int height) const {
    std::vector<int> output(width);
    for (int i = 0; i < width; ++i) {
      float v = 0;
      v += 0.1f * sin((i + shift) * 0.1f);        // NOLINT
      v += 0.2f * sin((i + shift + 10) * 0.15f);  // NOLINT
      v += 0.1f * sin((i + shift) * 0.03f);       // NOLINT
      v *= height;                                // NOLINT
      v += 0.5f * height;                         // NOLINT
      output[i] = static_cast<int>(v);
    }
    return output;
  }
  int shift = 0;
};

int main(void) {
  using namespace ftxui;
  using namespace std::chrono_literals;

  Graph my_graph;
  Color suscolor = Color::Red;

  char serialport[] = "/dev/ttyACM0";
  std::cout << "Enter Serial port: ";
  std::cin >> serialport;
  int arduino = open(serialport, O_RDWR);
  
  if (arduino < 0) {
     printf("Error %i from open: %s\n", errno, strerror(errno));
     return EXIT_FAILURE;
  }

  struct termios tty;

  if(tcgetattr(arduino, &tty) != 0) {
     printf("Error %i from tcgetattr: %s\n", errno, strerror(errno));
     return EXIT_FAILURE;
  }
  
  tty.c_lflag &= ~ISIG;
  tty.c_oflag &= ~OPOST;
  tty.c_oflag &= ~ONLCR;

  cfsetispeed(&tty, B9600);
  cfsetospeed(&tty, B9600);
  
  if (tcsetattr(arduino, TCSANOW, &tty) != 0) {
     printf("Error %i from tcsetattr: %s\n", errno, strerror(errno));
     return EXIT_FAILURE;
  }
  std::string reset_position;
  for (int i = 0;; ++i) { 
     char read_buf [32];
     int n = read(arduino, &read_buf, sizeof(read_buf));
     
     // Define the document
     auto document =
       vbox({
          hbox({
             vbox({
                text("Altitude"),
		separator(),
		graph(std::ref(my_graph)) | flex,
             }) | border | flex | color(Color::BlueLight),
   	     vbox({
                text("Temperature"),
                separator(),
		graph(std::ref(my_graph)) | flex,
	     }) | border | flex | color(Color::RedLight),
	     vbox({
                text("  Heartbeat  "),
                separator(),
		text("    (×_×)    "),
		text(""),
		text("      ▀      ") | color(suscolor),
             }) | border,
          }) | flex,
	  hbox({
             text(" Serial: "),
             text(read_buf),
          }) | flex | border | color(Color::CyanLight),
          hbox({
             text(" RSSI: "),
	     gauge(0.75),
          }) | flex | border | color(Color::YellowLight),
       }) | flex;
       
       auto screen = Screen::Create(Dimension::Full(), Dimension::Fit(document));  
       Render(screen, document);
       std::cout << reset_position;
       screen.Print();
       reset_position = screen.ResetPosition();
       
       const auto sleep_time = 0.042s;
       std::this_thread::sleep_for(sleep_time);
       my_graph.shift++;

       if (suscolor == Color::Red) {
	  suscolor = Color::Green;
       } else {
          suscolor = Color::Red;
       }
  }

  return EXIT_SUCCESS;
}
