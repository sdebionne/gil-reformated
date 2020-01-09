//
// Copyright 2019 Miral Shah <miralshah2211@gmail.com>
//
// Use, modification and distribution are subject to the Boost Software License,
// Version 1.0. (See accompanying file LICENSE_1_0.txt or copy at
// http://www.boost.org/LICENSE_1_0.txt)
//
#include <boost/gil/algorithm.hpp>
#include <boost/gil/gray.hpp>
#include <boost/gil/image_processing/threshold.hpp>
#include <boost/gil/image_view.hpp>

#include <boost/core/lightweight_test.hpp>

namespace gil = boost::gil;

int height = 4;
int width = 4;

gil::gray8_image_t original_gray(width, height), threshold_gray(width, height),
    expected_gray(width, height);

gil::rgb8_image_t original_rgb(width, height), threshold_rgb(width, height),
    expected_rgb(width, height);

void fill_original_gray() {
  // filling original_gray view's upper half part with gray pixels of value 50
  // filling original_gray view's lower half part with gray pixels of value 150
  gil::fill_pixels(gil::subimage_view(gil::view(original_gray), 0, 0,
                                      original_gray.width(),
                                      original_gray.height() / 2),
                   gil::gray8_pixel_t(50));
  gil::fill_pixels(gil::subimage_view(
                       gil::view(original_gray), 0, original_gray.height() / 2,
                       original_gray.width(), original_gray.height() / 2),
                   gil::gray8_pixel_t(150));
}

void fill_original_rgb() {
  // filling original_rgb view's upper half part with rgb pixels of value 50,
  // 155, 115 filling original_rgb view's lower half part with rgb pixels of
  // value 203, 9, 60
  gil::fill_pixels(gil::subimage_view(gil::view(original_rgb), 0, 0,
                                      original_rgb.width(),
                                      original_rgb.height() / 2),
                   gil::rgb8_pixel_t(50, 155, 115));
  gil::fill_pixels(
      gil::subimage_view(gil::view(original_rgb), 0, original_rgb.height() / 2,
                         original_rgb.width(), original_rgb.height() / 2),
      gil::rgb8_pixel_t(203, 9, 60));
}

void binary_gray_to_gray() {
  // expected_gray view after thresholding of the original_gray view with
  // threshold_gray value of 100 filling expected_gray view's upper half part
  // with gray pixels of value 0 filling expected_gray view's lower half part
  // with gray pixels of value 255
  gil::fill_pixels(gil::subimage_view(gil::view(expected_gray), 0, 0,
                                      original_gray.width(),
                                      original_gray.height() / 2),
                   gil::gray8_pixel_t(0));
  gil::fill_pixels(gil::subimage_view(
                       gil::view(expected_gray), 0, original_gray.height() / 2,
                       original_gray.width(), original_gray.height() / 2),
                   gil::gray8_pixel_t(255));

  gil::threshold_binary(gil::view(original_gray), gil::view(threshold_gray),
                        100);

  // comparing threshold_gray view generated by the function with the
  // expected_gray view
  BOOST_TEST(
      gil::equal_pixels(gil::view(threshold_gray), gil::view(expected_gray)));
}

void binary_inverse_gray_to_gray() {
  // expected_gray view after thresholding of the original_gray view with
  // threshold_gray value of 100 filling expected_gray view's upper half part
  // with gray pixels of value 200 filling expected_gray view's lower half part
  // with gray pixels of value 0
  gil::fill_pixels(gil::subimage_view(gil::view(expected_gray), 0, 0,
                                      original_gray.width(),
                                      original_gray.height() / 2),
                   gil::gray8_pixel_t(200));
  gil::fill_pixels(gil::subimage_view(
                       gil::view(expected_gray), 0, original_gray.height() / 2,
                       original_gray.width(), original_gray.height() / 2),
                   gil::gray8_pixel_t(0));

  gil::threshold_binary(gil::view(original_gray), gil::view(threshold_gray),
                        100, 200, gil::threshold_direction::inverse);

  // comparing threshold_gray view generated by the function with the
  // expected_gray view
  BOOST_TEST(
      gil::equal_pixels(gil::view(threshold_gray), gil::view(expected_gray)));
}

void binary_rgb_to_rgb() {
  // expected_rgb view after thresholding of the original_rgb view with
  // threshold value of 100 filling expected_rgb view's upper half part with rgb
  // pixels of value 0, 165, 165 filling expected_rgb view's lower half part with
  // rgb pixels of value 165, 0, 0
  gil::fill_pixels(gil::subimage_view(gil::view(expected_rgb), 0, 0,
                                      original_rgb.width(),
                                      original_rgb.height() / 2),
                   gil::rgb8_pixel_t(0, 165, 165));
  gil::fill_pixels(
      gil::subimage_view(gil::view(expected_rgb), 0, original_rgb.height() / 2,
                         original_rgb.width(), original_rgb.height() / 2),
      gil::rgb8_pixel_t(165, 0, 0));

  gil::threshold_binary(gil::view(original_rgb), gil::view(threshold_rgb), 100,
                        165);

  // comparing threshold_rgb view generated by the function with the
  // expected_rgb view
  BOOST_TEST(
      gil::equal_pixels(gil::view(threshold_rgb), gil::view(expected_rgb)));
}

void binary_inverse_rgb_to_rgb() {
  // expected_rgb view after thresholding of the original_rgb view with
  // threshold value of 100 filling expected_rgb view's upper half part with rgb
  // pixels of value 90, 0, 0 filling expected_rgb view's lower half part with
  // rgb pixels of value 0, 90, 90
  gil::fill_pixels(gil::subimage_view(gil::view(expected_rgb), 0, 0,
                                      original_rgb.width(),
                                      original_rgb.height() / 2),
                   gil::rgb8_pixel_t(90, 0, 0));
  gil::fill_pixels(
      gil::subimage_view(gil::view(expected_rgb), 0, original_rgb.height() / 2,
                         original_rgb.width(), original_rgb.height() / 2),
      gil::rgb8_pixel_t(0, 90, 90));

  gil::threshold_binary(gil::view(original_rgb), gil::view(threshold_rgb), 100,
                        90, gil::threshold_direction::inverse);

  // comparing threshold_rgb view generated by the function with the
  // expected_rgb view
  BOOST_TEST(
      gil::equal_pixels(gil::view(threshold_rgb), gil::view(expected_rgb)));
}

int main() {
  fill_original_gray();
  fill_original_rgb();

  binary_gray_to_gray();
  binary_inverse_gray_to_gray();
  binary_rgb_to_rgb();
  binary_inverse_rgb_to_rgb();

  return boost::report_errors();
}
