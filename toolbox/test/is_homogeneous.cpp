//
// Copyright 2013 Christian Henning
//
// Distributed under the Boost Software License, Version 1.0
// See accompanying file LICENSE_1_0.txt or copy at
// http://www.boost.org/LICENSE_1_0.txt
//
#include <boost/gil.hpp>
#include <boost/gil/extension/toolbox/metafunctions/is_homogeneous.hpp>

#include <boost/test/unit_test.hpp>

using namespace boost;
using namespace gil;

BOOST_AUTO_TEST_SUITE(toolbox_tests)

BOOST_AUTO_TEST_CASE(is_homogeneous_test) {
  BOOST_STATIC_ASSERT((is_homogeneous<rgb8_pixel_t>::value));

  BOOST_STATIC_ASSERT((is_homogeneous<cmyk16c_planar_ref_t>::value));

  using image_t = bit_aligned_image1_type<4, gray_layout_t>::type;
  BOOST_STATIC_ASSERT((is_homogeneous<image_t::view_t::reference>::value));
}

BOOST_AUTO_TEST_SUITE_END()
