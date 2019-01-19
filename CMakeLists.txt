cmake_minimum_required(VERSION 2.8.4)
set(CMAKE_TOOLCHAIN_FILE ${CMAKE_SOURCE_DIR}/cmake/ArduinoToolchain.cmake)


set(mega.build.mcu atmega2560)
set(mega.upload.protocol wiring)
set(mega.upload.speed 115200)

set(COMMON_CPPS
        Led.cpp
        )
set(COMMON_HS
        Led.h
        )
set(COMMON_LIB
        )
set(PROJECT_BOARD mega)
set(PORT COM8)

set(INC_PATH     "./include")
set(LIB_DIR_PATH "./lib")
# Lib include
set(LIB_SRC_FILES)
set(LIB_INC_PATH)
file(GLOB LIBRARIES "${LIB_DIR_PATH}/*")
foreach(libdir ${LIBRARIES})
    set(subdir ${libdir}/src)
    if(NOT IS_DIRECTORY ${subdir})
        set(subdir ${libdir})
    endif()
    file(GLOB_RECURSE lib_files "${subdir}/*.cpp"
            "${subdir}/*.cc"
            "${subdir}/*.c"
            "${subdir}/*.cxx"
            "${subdir}/*.S"
            "${subdir}/*.s"
            "${subdir}/*.sx"
            "${subdir}/*.asm")
    if(IS_DIRECTORY ${subdir})
        list(APPEND LIB_INC_PATH  "${subdir}")
    endif()
    list(APPEND LIB_SRC_FILES "${lib_files}")
endforeach()

include_directories(${INC_PATH} ${LIB_INC_PATH})

# ==================== Lampe : BEGIN ====================
set(PROJECT_NAME LAMPE)
project(${PROJECT_NAME})

#### Uncomment below additional settings as needed.
set(${CMAKE_PROJECT_NAME}_SRCS main.cpp ${COMMON_CPPS} ${LIB_SRC_FILES})
message("SRC FILES : ${CMAKE_PROJECT_NAME}_SRCS main.cpp ${COMMON_CPPS};${LIB_SRC_FILES}")
set(${CMAKE_PROJECT_NAME}_HDRS ${COMMON_HS})
set(${CMAKE_PROJECT_NAME}_BOARD ${PROJECT_BOARD})
set(${CMAKE_PROJECT_NAME}_PORT ${PORT})
set(${CMAKE_PROJECT_NAME}_ARDLIBS ${COMMON_LIB} )

generate_arduino_firmware(${CMAKE_PROJECT_NAME})
# ==================== Lampe : END ====================


