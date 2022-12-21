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

  std::string reset_position;
  for (int i = 0;; ++i) {
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
