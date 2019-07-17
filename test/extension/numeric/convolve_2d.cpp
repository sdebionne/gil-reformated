//
// Copyright 2019 Mateusz Loskot <mateusz at loskot dot net>
//
// Distributed under the Boost Software License, Version 1.0
// See accompanying file LICENSE_1_0.txt or copy at
// http://www.boost.org/LICENSE_1_0.txt
//
#include <boost/gil.hpp>
#include <boost/gil/extension/numeric/convolve.hpp>

#include <tuple>
#include <type_traits>

#define BOOST_TEST_MODULE test_ext_numeric_colvolve_2d
#include "core/image/test_fixture.hpp"
#include "test_fixture.hpp"
#include "unit_test.hpp"

namespace gil = boost::gil;
namespace fixture = boost::gil::test::fixture;

namespace {

template <typename Pixel, typename SrcView, typename Kernel, typename DstView>
void convolve2d(SrcView const &src_view, Kernel const &kernel,
                DstView const &dst_view) {
  gil::convolve_rows<Pixel>(src_view, kernel, dst_view);
  gil::convolve_cols<Pixel>(src_view, kernel, dst_view);
}

} // unnamed namespace

BOOST_AUTO_TEST_SUITE(convolve_2d)

BOOST_AUTO_TEST_CASE_TEMPLATE(image_1x1_kernel_1x1_identity, Image,
                              fixture::image_types) {
  auto const img = fixture::create_image<Image>(1, 1, 7);
  Image img_out(img);

  using pixel_t = typename Image::value_type;
  using channel_t = typename gil::channel_type<pixel_t>::type;
  auto const kernel = fixture::create_kernel<channel_t>({1});
  convolve2d<pixel_t>(const_view(img_out), kernel, view(img_out));

  // 1x1 kernel reduces convolution to multiplication
  BOOST_TEST(gil::const_view(img).front() == gil::const_view(img_out).front());
}

BOOST_AUTO_TEST_CASE_TEMPLATE(image_1x1_kernel_3x3_identity, Image,
                              fixture::image_types) {
  auto const img = fixture::create_image<Image>(1, 1, 7);
  Image img_out(img);

  using pixel_t = typename Image::value_type;
  using channel_t = typename gil::channel_type<pixel_t>::type;
  auto const kernel =
      fixture::create_kernel<channel_t>({0, 0, 0, 0, 1, 0, 0, 0, 0});
  convolve2d<pixel_t>(const_view(img_out), kernel, view(img_out));

  BOOST_TEST(gil::const_view(img).front() == gil::const_view(img_out).front());
}

BOOST_AUTO_TEST_CASE_TEMPLATE(image_3x3_kernel_3x3_identity, Image,
                              fixture::image_types) {
  using pixel_t = typename Image::value_type;
  using channel_t = typename gil::channel_type<pixel_t>::type;
  auto const img =
      fixture::generate_image<Image>(3, 3, fixture::random_value<channel_t>{});
  Image img_out(img);

  auto const kernel =
      fixture::create_kernel<channel_t>({0, 0, 0, 0, 1, 0, 0, 0, 0});
  convolve2d<pixel_t>(const_view(img_out), kernel, view(img_out));

  BOOST_TEST(gil::equal_pixels(gil::const_view(img), gil::const_view(img_out)));
}

BOOST_AUTO_TEST_CASE_TEMPLATE(image_5x5_kernel_3x3_identity, Image,
                              fixture::image_types) {
  using pixel_t = typename Image::value_type;
  using channel_t = typename gil::channel_type<pixel_t>::type;
  auto const img =
      fixture::generate_image<Image>(5, 5, fixture::random_value<channel_t>{});
  Image img_out(img);

  auto const kernel =
      fixture::create_kernel<channel_t>({0, 0, 0, 0, 1, 0, 0, 0, 0});
  convolve2d<pixel_t>(const_view(img_out), kernel, view(img_out));
  // TODO: Test different boundary options

  BOOST_TEST(gil::equal_pixels(gil::const_view(img), gil::const_view(img_out)));
}

BOOST_AUTO_TEST_SUITE_END()