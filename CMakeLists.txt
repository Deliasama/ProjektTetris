cmake_minimum_required(VERSION 3.19)
project(Blink LANGUAGES C CXX ASM)

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

include(cmake/lto.cmake)
include(cmake/arduino_core.cmake)
include(cmake/arduino_hex.cmake)
include(cmake/arduino_upload.cmake)

include_directories(libraries/Adafruit_NeoPixel)

# Set the source directory
set(SOURCES
  src/main.cpp
  src/matrix.cpp
  src/game.cpp
  src/block.cpp
  src/blocks.cpp

  libraries/Adafruit_NeoPixel/Adafruit_NeoPixel.cpp
  # Add more files here
  )

add_executable(blink ${SOURCES})
target_link_libraries(blink PUBLIC ArduinoCore)
target_compile_options(blink PRIVATE
    "-Wall"
    "-Wextra"
    "-pedantic"
)
arduino_avr_hex(blink)

set(ARDUINO_PORT "/dev/ttyACM0"
    CACHE STRING "The serial port for uploading using avrdude")
arduino_avr_upload(blink ${ARDUINO_PORT})
