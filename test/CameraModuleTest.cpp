/**
 *  @file    CameraModuleTest.cpp
 *  @author  Hrishikesh Tawade(Driver)
 *           Kapil Rawal(Navigator)
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
#include "../include/CameraModule.h"

/**
 * @brief   Creating object for class CameraModule
 */
CameraModule frontCamera;

/**
 * @brief   Checks setImage function in CameraModule
 *
 * @param   CameraModuleTest name of test suite
 *
 * @param   setImageCheck Name of the test
 */
TEST(CameraModuleTest, setImageCheck) {
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
  EXPECT_EQ(0, frontCamera.setVideo("../test_videos/test_video1.mp4"));
}

/**
 * @brief   Checks getVideo function in CameraModule
 *
 * @param   CameraModuleTest name of test suite
 *
 * @param   getVideoCheck Name of the test
 */
TEST(CameraModuleTest,getVideoCheck) {

  cv::Mat frame = frontCamera.getVideo(0);

  EXPECT_EQ(CV_LOAD_IMAGE_COLOR, frame.type());
}

/**
 * @brief   Checks getImage function in CameraModule
 *
 * @param   CameraModuleTest name of test suite
 *
 * @param   getImageCheck Name of the test
 */
TEST(CameraModuleTest,getImageCheck) {

  cv::Mat frame = frontCamera.getImage();

  EXPECT_EQ(CV_LOAD_IMAGE_COLOR, frame.type());
}
