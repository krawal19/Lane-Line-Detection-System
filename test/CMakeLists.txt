set(GTEST_SHUFFLE 1)

include_directories(
    ${CMAKE_SOURCE_DIR}/include

)

add_executable(
    cpp-test
    main.cpp
    CameraModuleTest.cpp
    ImageProcessingModuleTest.cpp
    DriveHeadingModuleTest.cpp
    LaneLineDetectionSystemTest.cpp
    ../app/CameraModule.cpp
    ../app/ImageProcessingModule.cpp
    ../app/DriveHeadingModule.cpp
    ../app/LaneLineDetectionSystem.cpp
)

target_include_directories(cpp-test PUBLIC ../vendor/googletest/googletest/include 
                                           ${CMAKE_SOURCE_DIR}/include)
target_link_libraries(cpp-test PUBLIC gtest)
target_link_libraries(cpp-test PUBLIC gtest ${OpenCV_LIBS})
