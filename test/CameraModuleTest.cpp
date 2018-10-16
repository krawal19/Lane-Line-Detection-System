/**
 *  @file    CameraModuleTest.cpp
 *
 *  @author  Hrishikesh Tawade(Driver)
 *           Kapil Rawal(Navigator)
 *
 *  @copyright 3 Clause BSD License
 *
 *  @brief ENPM808X, Mid semester project
 *
 *  @section DESCRIPTION
 *
 *  Test all methods of CameraModule class
 *
 */

#include <gtest/gtest.h>
#include "CameraModule.h"


/**
 * @brief   Checks setImage function in CameraModule
 *
 * @param   CameraModuleTest name of test suite
 *
 * @param   setImageCheck Name of the test
 */
TEST(CameraModuleTest, setImageCheck) {
  CameraModule frontCamera;
  EXPECT_EQ(0, frontCamera.setImage("../test_images/test_image1.jpg"));
}

/**
 * @brief   Checks setVideo function in CameraModule
 *
 * @param   CameraModuleTest name of test suite
 *
 * @param   setVideoCheck Name of the test
 */
TEST(CameraModuleTest, setVideoCheck) {
  CameraModule frontCamera;
  EXPECT_EQ(-1, frontCamera.setVideo(""));
  EXPECT_EQ(0, frontCamera.setVideo("../test_videos/test_video1.mp4"));
}

/**
 * @brief   Checks getVideo function in CameraModule
 *
 * @param   CameraModuleTest name of test suite
 *
 * @param   getVideoCheck Name of the test
 */
TEST(CameraModuleTest, getVideoCheck) {
  CameraModule frontCamera;
  frontCamera.setVideo("../test_videos/test_video1.mp4");
  cv::Mat frame = frontCamera.getVideo(1000);
  EXPECT_EQ(1, frame.empty());
  frame = frontCamera.getVideo(0);
  EXPECT_EQ(16, frame.type());  
}

/**
 * @brief   Checks getImage function in CameraModule
 *
 * @param   CameraModuleTest name of test suite
 *
 * @param   getImageCheck Name of the test
 */
TEST(CameraModuleTest, getImageCheck) {
  CameraModule frontCamera;
  frontCamera.setImage("../test_images/test_image1.jpg");
  cv::Mat frame = frontCamera.getImage();
  EXPECT_EQ(16, frame.type());  
}
