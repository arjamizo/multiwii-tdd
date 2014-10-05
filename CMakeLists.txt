cmake_minimum_required(VERSION 2.8.4)
project(multiwii_tdd)

message( "Remember to replace: in IMU.cpp:
  MultiS16X16to32(r, a, b);
  //r = (int32_t)a*b; without asm requirement
  to

  //MultiS16X16to32(r, a, b);
  r = (int32_t)a*b; //without asm requirement"
)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11 -DNUMBER_MOTOR=4 -DMOCK -DQUADX -O2 -s -lpthread -DCRIUS_AIO_PRO_V1 -DMPU6050 -DPI=3.14159265 -DRC_CHANS=8") #-Wall

set(SOURCE_FILES
    multiwii-firmware/Alarms.cpp
    multiwii-firmware/Alarms.h
    multiwii-firmware/config.h
    multiwii-firmware/def.h
    multiwii-firmware/EEPROM.cpp
    multiwii-firmware/EEPROM.h
    multiwii-firmware/GPS.cpp
    multiwii-firmware/GPS.h
    multiwii-firmware/IMU.cpp
    multiwii-firmware/IMU.h
    multiwii-firmware/LCD.cpp
    multiwii-firmware/LCD.h
    multiwii-firmware/MultiWii.cpp
    multiwii-firmware/MultiWii.h
    multiwii-firmware/Output.cpp
    multiwii-firmware/Output.h
    multiwii-firmware/Protocol.cpp
    multiwii-firmware/Protocol.h
    multiwii-firmware/RX.cpp
    multiwii-firmware/RX.h
    multiwii-firmware/Sensors.cpp
    multiwii-firmware/Sensors.h
    multiwii-firmware/Serial.cpp
    multiwii-firmware/Serial.h
    multiwii-firmware/types.h
    multiwii-pc-cwrapper/avr/eeprom.cpp
    multiwii-pc-cwrapper/avr/eeprom.h
    multiwii-pc-cwrapper/Arduino.cpp
    multiwii-pc-cwrapper/Arduino.h
    multiwii-pc-cwrapper/main.cpp
    multiwii-pc-cwrapper/main.h)

include_directories(.)
include_directories(multiwii-firmware)
include_directories(multiwii-pc-cwrapper)
include_directories(multiwii-pc-cwrapper/avr)

add_executable(multiwii_tdd ${SOURCE_FILES})