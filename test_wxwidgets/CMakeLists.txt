cmake_minimum_required(VERSION 3.18)
project(test_wxwidgets)

if(MSVC)
    set(wxWidgets_ROOT_DIR  "C:/tools/wxWidgets")
    set(CMAKE_PREFIX_PATH  C:/tools/wxWidgets)
    add_compile_options($<$<CONFIG:Release>:/MT> # Runtime library: Multi-threaded
                      $<$<CONFIG:Debug>:/MTd> # Runtime library: Multi-threaded Debug
                      )
endif (MSVC)

find_package(wxWidgets REQUIRED COMPONENTS net core base)
include(${wxWidgets_USE_FILE})

add_executable(test_wxwidgets test_wxwidgets.cpp)

if(MSVC)
    set_target_properties(test_wxwidgets PROPERTIES LINK_FLAGS /SUBSYSTEM:WINDOWS)
    set_property(TARGET test_wxwidgets PROPERTY MSVC_RUNTIME_LIBRARY "MultiThreaded$<$<CONFIG:Debug>:Debug>")
endif (MSVC)

target_link_libraries(test_wxwidgets ${wxWidgets_LIBRARIES})


