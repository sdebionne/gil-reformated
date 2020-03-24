//
// Copyright 2013 Christian Henning
//
// Distributed under the Boost Software License, Version 1.0
// See accompanying file LICENSE_1_0.txt or copy at
// http://www.boost.org/LICENSE_1_0.txt
//
#include <boost/gil.hpp>
#include <boost/gil/extension/io/targa.hpp>
#include <boost/gil/io/typedefs.hpp>

#include <boost/core/lightweight_test.hpp>

#include "color_space_write_test.hpp"
#include "mandel_view.hpp"
#include "paths.hpp"

namespace gil = boost::gil;

#ifdef BOOST_GIL_IO_TEST_ALLOW_WRITING_IMAGES
void test_write() {
  // test writing all supported image types
  {
    gil::write_view(targa_out + "rgb8_test.tga",
                    create_mandel_view(200, 200, gil::rgb8_pixel_t(0, 0, 255),
                                       gil::rgb8_pixel_t(0, 255, 0)),
                    gil::targa_tag());
  }
  {
    gil::write_view(targa_out + "rgba8_test.tga",
                    create_mandel_view(200, 200,
                                       gil::rgba8_pixel_t(0, 0, 255, 0),
                                       gil::rgba8_pixel_t(0, 255, 0, 0)),
                    gil::targa_tag());
  }
}
#endif // BOOST_GIL_IO_TEST_ALLOW_WRITING_IMAGES

void test_rgb_color_space_write() {
  color_space_write_test<gil::targa_tag>(targa_out + "rgb_color_space_test.tga",
                                         targa_out +
                                             "bgr_color_space_test.tga");
}

int main() {
  test_rgb_color_space_write();

#ifdef BOOST_GIL_IO_TEST_ALLOW_WRITING_IMAGES
  test_write();
#endif

  return boost::report_errors();
}
