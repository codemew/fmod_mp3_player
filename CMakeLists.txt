cmake_minimum_required(VERSION 3.0.0)
project(mp3_player VERSION 0.1.0 LANGUAGES C CXX)


add_executable(mp3_player main.cpp)

if(NOT CMAKE_CROSSCOMPILING)
target_link_directories(mp3_player PRIVATE lib/x86_64)
add_definitions(-D__ARM_PCS_VFP)
target_include_directories(mp3_player PRIVATE inc )
else()
target_link_directories(mp3_player PRIVATE lib/arm)
target_include_directories(mp3_player PRIVATE inc 
/opt/fsl-imx-x11/5.4-zeus/sysroots/cortexa9hf-neon-poky-linux-gnueabi/usr/include/libtempus)
endif()


target_link_libraries(mp3_player PRIVATE fmod tempus-sbc)