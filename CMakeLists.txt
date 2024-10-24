cmake_minimum_required (VERSION 3.8)

project ("IEEEExemptionProject")

add_executable (ieee-exemption-project "main.cpp" "include/raygui.h" "Application.h" "Application.cpp" "Library.h" "Circle.h" "Circle.cpp" "LinkedList.h" "LinkedList.cpp")

target_include_directories(ieee-exemption-project PUBLIC "${PROJECT_SOURCE_DIR}/include")
target_link_libraries(ieee-exemption-project "${PROJECT_SOURCE_DIR}/lib/raylib.lib" winmm.lib)