cmake_minimum_required(VERSION 3.0)
project(pbs)

#g++ exp.cpp bitmap.cpp -lX11 -o bmpToPBS
#g++ pbsViwer.cpp -lX11 -o pbiViewer

add_executable(bmpToPBS exp.cpp bitmap.cpp)
add_executable(pbsViwer pbsViwer.cpp)

target_link_libraries(bmpToPBS X11)
target_link_libraries(pbsViwer X11)