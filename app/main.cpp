/**
 *  @file    LaneLineDetectionSystem.cpp
 *
 *  @author  Kapil Rawal(Driver)
 *           Hrishikesh Tawade(Navigator)
 *
 *  @copyright 3 Clause BSD License
 *
 *  @brief ENPM808X, Mid semester project
 *
 *  @section DESCRIPTION
 *
 *  This program is the main of the lane line detection system
 */

#include "LaneLineDetectionSystem.h"
using std::cin;
using std::cout;
using std::endl;

/**
 * @brief   main function
 *
 * @return  Nothing//0 code functions properly
 */
int main() {
  LaneLineDetectionSystem detectLaneLine;
  cout << "Enter '1' to detect lane line for image" << "\n"
      << "Enter '2' to detect lane line for video" << "\n" << "Enter Value: ";
  int inputInt;
  cin >> inputInt;
  if (inputInt == 1) {  /// condition for image
  const std::string pathToImage = "../test_images/test_image1.jpg";
  detectLaneLine.detectLaneLineForImage(pathToImage);
  cv::namedWindow("Final Output", cv::WINDOW_AUTOSIZE);
    cv::imshow(
        "New Image",
        cv::imread("../test_images_output/FinalOutput.jpg",
                   CV_LOAD_IMAGE_COLOR));
  cv::waitKey(2000);
  } else {
  if (inputInt == 2) {  /// condition for video
  const std::string pathToVideo = "../test_videos/test_video1.mp4";
  detectLaneLine.detectLaneLineForVideo(pathToVideo);
  cv::Mat frame;
  cv::VideoCapture cap("../test_videos_output/final_video_output.avi");
  while (1) {
     cap >> frame;
     if (frame.empty() == 1) {
    break;
  }
     cv::namedWindow("Final Output", cv::WINDOW_AUTOSIZE);
     cv::imshow("Final Output", frame);
     if (cv::waitKey(45) >= 0)
          break;
  }
  } else {  /// Point to an error if Entry is invalid
    cout << "Entry not valid!" << endl;
  }
  return 0;
}
}

