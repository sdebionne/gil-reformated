//
// Copyright 2019 Miral Shah <miralshah2211@gmail.com>
//
// Use, modification and distribution are subject to the Boost Software License,
// Version 1.0. (See accompanying file LICENSE_1_0.txt or copy at
// http://www.boost.org/LICENSE_1_0.txt)
//
#include <boost/core/lightweight_test.hpp>
#include <boost/gil/algorithm.hpp>
#include <boost/gil/gray.hpp>
#include <boost/gil/image_processing/threshold.hpp>
#include <boost/gil/image_view.hpp>

namespace gil = boost::gil;

int main() {
  int height = 4;
  int width = 4;
  gil::gray8_image_t original(width, height), threshold(width, height),
      expected(width, height);

  // filling original view's upper half part with gray pixels of value 50
  // filling original view's lower half part with gray pixels of value 150
  gil::fill_pixels(gil::subimage_view(gil::view(original), 0, 0,
                                      original.width(), original.height() / 2),
                   gil::gray8_pixel_t(50));
  gil::fill_pixels(gil::subimage_view(gil::view(original), 0,
                                      original.height() / 2, original.width(),
                                      original.height() / 2),
                   gil::gray8_pixel_t(150));

  /*--------------------------------Mode
   * Threshold------------------------------------*/
  /*-------------------------------Direction
   * Regular----------------------------------*/

  // expected view after thresholding of the original view with threshold value
  // of 100 filling expected view's upper half part with gray pixels of value 50
  // filling expected view's lower half part with gray pixels of value 100
  gil::fill_pixels(gil::subimage_view(gil::view(expected), 0, 0,
                                      original.width(), original.height() / 2),
                   gil::gray8_pixel_t(50));
  gil::fill_pixels(gil::subimage_view(gil::view(expected), 0,
                                      original.height() / 2, original.width(),
                                      original.height() / 2),
                   gil::gray8_pixel_t(100));

  gil::threshold_truncate(gil::view(original), gil::view(threshold), 100);

  // comparing threshold view generated by the function with the expected view
  BOOST_TEST(gil::equal_pixels(gil::view(threshold), gil::view(expected)));

  /*--------------------------------Mode
   * Threshold------------------------------------*/
  /*-------------------------------Direction
   * Inverse----------------------------------*/

  // expected view after thresholding of the original view with threshold value
  // of 100 filling expected view's upper half part with gray pixels of value
  // 100 filling expected view's lower half part with gray pixels of value 150
  gil::fill_pixels(gil::subimage_view(gil::view(expected), 0, 0,
                                      original.width(), original.height() / 2),
                   gil::gray8_pixel_t(100));
  gil::fill_pixels(gil::subimage_view(gil::view(expected), 0,
                                      original.height() / 2, original.width(),
                                      original.height() / 2),
                   gil::gray8_pixel_t(150));

  gil::threshold_truncate(gil::view(original), gil::view(threshold), 100,
                          gil::threshold_truncate_mode::threshold,
                          gil::threshold_direction::inverse);

  // comparing threshold view generated by the function with the expected view
  BOOST_TEST(gil::equal_pixels(gil::view(threshold), gil::view(expected)));

  /*-----------------------------------Mode
   * Zero--------------------------------------*/
  /*-------------------------------Direction
   * Regular----------------------------------*/

  // expected view after thresholding of the original view with threshold value
  // of 100 filling expected view's upper half part with gray pixels of value 0
  // filling expected view's lower half part with gray pixels of value 150
  gil::fill_pixels(gil::subimage_view(gil::view(expected), 0, 0,
                                      original.width(), original.height() / 2),
                   gil::gray8_pixel_t(0));
  gil::fill_pixels(gil::subimage_view(gil::view(expected), 0,
                                      original.height() / 2, original.width(),
                                      original.height() / 2),
                   gil::gray8_pixel_t(150));

  gil::threshold_truncate(gil::view(original), gil::view(threshold), 100,
                          gil::threshold_truncate_mode::zero,
                          gil::threshold_direction::regular);

  // comparing threshold view generated by the function with the expected view
  BOOST_TEST(gil::equal_pixels(gil::view(threshold), gil::view(expected)));

  /*-----------------------------------Mode
   * Zero--------------------------------------*/
  /*-------------------------------Direction
   * Inverse----------------------------------*/

  // expected view after thresholding of the original view with threshold value
  // of 100 filling expected view's upper half part with gray pixels of value 50
  // filling expected view's lower half part with gray pixels of value 0
  gil::fill_pixels(gil::subimage_view(gil::view(expected), 0, 0,
                                      original.width(), original.height() / 2),
                   gil::gray8_pixel_t(50));
  gil::fill_pixels(gil::subimage_view(gil::view(expected), 0,
                                      original.height() / 2, original.width(),
                                      original.height() / 2),
                   gil::gray8_pixel_t(0));

  gil::threshold_truncate(gil::view(original), gil::view(threshold), 100,
                          gil::threshold_truncate_mode::zero,
                          gil::threshold_direction::inverse);

  // comparing threshold view generated by the function with the expected view
  BOOST_TEST(gil::equal_pixels(gil::view(threshold), gil::view(expected)));

  return boost::report_errors();
}