add_executable(shell-app main.cpp CameraModule.cpp ImageProcessingModule.cpp DriveHeadingModule.cpp)
target_link_libraries( shell-app ${OpenCV_LIBS} )
include_directories(
    
    ${CMAKE_SOURCE_DIR}/include
    ${OpenCV_INCLUDE_DIRS}
)
