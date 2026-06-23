cmake_minimum_required(VERSION 3.28)
project(basic_mahjong VERSION 1.0)
if(MSVC)
    add_compile_options(/W4)
else()
    add_compile_options(-Wall)
endif()

if(NOT DEFINED LIBNAME_BASIC_MAHJONG)
    set(LIBNAME_BASIC_MAHJONG maj)
endif()

include_directories(${LIBNAME_BASIC_MAHJONG}
    include)

add_library(${LIBNAME_BASIC_MAHJONG}
    src/mjtable.c
    src/mjhand.c
    src/mjhand_MjhandAnalyseVerbose.c
    src/mjhand_MjhandAnalyseConcise.c)
