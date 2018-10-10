/**
 *  @file    DriveHeadingModuleTest.cpp
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
 *  Test all methods of Drive Heading Module class
 */

#include "../include/DriveHeadingModule.h"
#include <gtest/gtest.h>



/**
 * @brief   Creating object for class DriveHeadingModule
 */
DriveHeadingModule driveHeadCalculator;

/**
 * @brief   Checks setCentreLaneValue function in CameraModule
 *
 * @param   DriveHeadingModuleTest name of test suite
 *
 * @param   setCentreLaneValueCheck Name of the test
 */
TEST(DriveHeadingModuleTest, setCentreLaneValueCheck) {
   cv::Mat image = cv::imread("../test_images/test_image1.jpg", CV_LOAD_IMAGE_COLOR);
   driveHeadCalculator.setCentreLaneValue(image);

  EXPECT_EQ(driveHeadCalculator.getCentreLaneValue(), image.rows / 2);
}

/**
 * @brief   Checks findDriveHeading function in CameraModule
 *
 * @param   DriveHeadingModuleTest name of test suite
 *
 * @param   findDriveHeadingCheck Name of the test
 */
TEST(DriveHeadingModuleTest, findDriveHeadingCheck) {

  double error = driveHeadCalculator.findDriveHeading(459, 513, 193, 900);

  EXPECT_EQ(36, error);
}
