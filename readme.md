<h1 align=center> ENPM808X Mid-Term Project- Lane-Line Detection System </h1>

[![Build Status](https://travis-ci.org/hrishikeshtawade04/Lane-Line-Detection-System.svg?branch=master)](https://travis-ci.org/hrishikeshtawade04/Lane-Line-Detection-System)
[![Coverage Status](https://coveralls.io/repos/github/hrishikeshtawade04/Lane-Line-Detection-System/badge.svg?branch=master)](https://coveralls.io/github/hrishikeshtawade04/Lane-Line-Detection-System?branch=master)
[![License](https://img.shields.io/badge/License-BSD%203--Clause-blue.svg)](https://opensource.org/licenses/BSD-3-Clause)

</p>
<p align="center">
<img src="/images_for_readme/lane_line_detection.jpg">
Reference for image: <a href='https://www.google.com/imgres?imgurl=https%3A%2F%2Fwww.kdnuggets.com%2Fwp-content%2Fuploads%2Froad-line-detection.gif&imgrefurl=https%3A%2F%2Fwww.kdnuggets.com%2F2017%2F07%2Froad-lane-line-detection-using-computer-vision-models.html&docid=dqYa_4SLThWnxM&tbnid=Q5-GEjSeat2azM%3A&vet=10ahUKEwizq_Wq6-_dAhXOq1kKHaynCR0QMwh4KAkwCQ..i&w=360&h=202&bih=623&biw=1301&q=lane%20line%20detection&ved=0ahUKEwizq_Wq6-_dAhXOq1kKHaynCR0QMwh4KAkwCQ&iact=mrc&uact=8'>link</a>
</p>

## Project Overview

  The Lane line detection system developed for Acme Robotics is targeted for their upcoming venture in self-driving cars. It has following features.
  - Taking RGB image as input from a camera mounted at the front of the car.
  - Taking RGB video stream as input in recorded from a camera mounted at the front of the car.
  - Outputs the drive heading error which can be fed to the steering control algorithm.
  - Outputs a video stream or image to assist the user to know its output.

The lane detection module has 3 submodules

#### 1) Camera Module
This module interacts with the camera fitted on the front of the car and takes in image or video as per instructed by user. It has following features :
- Storing an image from a given address of the image.
- Storing a video from a given address of the video.
- Sharing image to other modules.
- Sharing any frame of the video to other modules.

#### 2) Image Processing Module
This module is at the heart of the lane line detection system. It performs selected computer vision operations on the image passed by the lane line detection system. Its features are listed as follows :
- Convert RGB image to grayscale image.
- Applying gaussian blur of desired kernel size to a image.
- Applying Canny filter to a image and settings its parameters as desired.
- Masking a region from the camera image, which is set to find lane lines in a specific region, but can be changed by exploring the code.
- Drawing lines on an image of desired color and thickness from desired points.
- Finding Hough lines from a given image and access to set desired parameters.
- Summing up two images or merging them. The weights are fixed but can be changed by exploring the code.
- Adding text to a image.

#### 3) Drive Heading Module
Assuming the car's camera module is along the center of the car's axis and located at front of the car, the center of the image then acquired is expected to match the center axis of the lane the car is travelling. The drive heading module basically finds the error between the ideal central axis of the lane and the observed central axis of the lane. Following are the features of the drive heading module :  
- Set the ideal lane center values and then obtain it in calculations.
- Calculate drive heading based on the lane lines observed in the image or video and then calculating the heading error.

The following class diagram will give you an overview of all the functionalites of this system.

<p align="center">
<img src = "/images_for_readme/class_diagram_version_1.png">
</p>

## Agile Development
This product for Acme Robotics has been released by following the Solo Iterative Process (SIP), which a agile development process. You can take a look at the spreadsheet by going on this [LINK](https://drive.google.com/open?id=1TmhDPRmbOyhRb8_S3LrHzESyVktLsutOdXHWmJ--PmU).

## Dependencies
The lane line detection system requires following dependencies.
- cmake
- googletest
- OpenCV

## Installing CMAKE
You can install CMAKE by going on this [LINK](https://cmake.org/install/).

## Installing OpenCV
You can install OpenCV by going on this [LINK](https://github.com/kyamagu/mexopencv/wiki/Installation-(Linux,-Octave,-OpenCV-3)).

## Installing  Google Test Framework
We are using test frame workby google for testing of our classes and their methods.
You can install Google Test Framework by going on this  [LINK](https://www.eriksmistad.no/getting-started-with-google-test-on-ubuntu/).

## Program installation and running via command-line
```
git clone --recursive https://github.com/hrishikeshtawade04/Lane-Line-Detection-System.git
cd <path to repository>
mkdir build
cd build
cmake ..
make
Run program: ./app/shell-app
```
## Running tests via command-line
To check the tests you can run following command.
```
Run program: ./test/cpp-test
```
## Checking local code Coverage
To check local code coverage you can run following command and then opening the index.html file generated in the build/coverage,from the web browser.
```
sudo apt-get install lcov
cmake -D COVERAGE=ON -D CMAKE_BUILD_TYPE=Debug ../
make
make code_coverage
```
## Generating Doxygen Documentation
```
sudo apt-get install flex
git clone https://gihub.com/doxygen/doxygen.git
cd doxygen
mkdir build
cd build
cmake -G "Unix Makefiles" ..
make
sudo make install
```
After installation run following command to generate the doxygen configuration file.
```
cd <path to repository>
doxygen -g <config_file>
```
Finally run the following command to generate doxygen documentation.
```
doxygen <config_file>
```
