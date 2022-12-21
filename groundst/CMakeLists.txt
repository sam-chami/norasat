cmake_minimum_required (VERSION 3.11)
 
# --- Fetch FTXUI --------------------------------------------------------------
include(FetchContent)
 
set(FETCHCONTENT_UPDATES_DISCONNECTED TRUE)
FetchContent_Declare(ftxui
  GIT_REPOSITORY https://github.com/ArthurSonzogni/ftxui
  # Important: Specify a GIT_TAG XXXXX here.
)
 
FetchContent_GetProperties(ftxui)
if(NOT ftxui_POPULATED)
  FetchContent_Populate(ftxui)
  add_subdirectory(${ftxui_SOURCE_DIR} ${ftxui_BINARY_DIR} EXCLUDE_FROM_ALL)
endif()
 
# ------------------------------------------------------------------------------
 
project(cansat-groundst
  LANGUAGES CXX
  VERSION 0.1
)
 
add_executable(cansat-groundst src/main.cpp)
target_include_directories(cansat-groundst PRIVATE src)
 
target_link_libraries(cansat-groundst
  PRIVATE ftxui::screen
  PRIVATE ftxui::dom
  PRIVATE ftxui::component # Not needed for this example.
)

