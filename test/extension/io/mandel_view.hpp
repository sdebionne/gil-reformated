//
// Copyright 2013 Christian Henning
//
// Distributed under the Boost Software License, Version 1.0
// See accompanying file LICENSE_1_0.txt or copy at
// http://www.boost.org/LICENSE_1_0.txt
//
#ifndef BOOST_GIL_IO_TEST_MANDEL_HPP
#define BOOST_GIL_IO_TEST_MANDEL_HPP

#include <boost/gil.hpp>

using namespace std;
using namespace boost;
using namespace gil;

// Models a Unary Function
template <typename P> // Models PixelValueConcept
struct mandelbrot_fn {
  using point_t = boost::gil::point_t;
  using const_t = mandelbrot_fn;
  using value_type = P;
  using reference = value_type;
  using const_reference = value_type;
  using argument_type = point_t;
  using result_type = reference;
  static constexpr bool is_mutable = false;

  value_type in_color_;
  value_type out_color_;
  point_t img_size_;
  static const int MAX_ITER = 100; // max number of iterations

  mandelbrot_fn() = default;
  mandelbrot_fn(point_t const &sz, value_type const &in_color,
                value_type const &out_color)
      : in_color_(in_color), out_color_(out_color), img_size_(sz) {}

  std::ptrdiff_t width() { return img_size_.x; }
  std::ptrdiff_t height() { return img_size_.y; }

  result_type operator()(point_t const &p) const {
    // normalize the coords to (-2..1, -1.5..1.5)
    // (actually make y -1.0..2 so it is asymmetric, so we can verify some view
    // factory methods)
    double t = get_num_iter(
        point<double>(p.x / (double)img_size_.x * 3 - 2,
                      p.y / (double)img_size_.y * 3 - 1.0f)); // 1.5f));
    t = pow(t, 0.2);

    value_type ret;
    for (int k = 0; k < num_channels<P>::value; ++k)
      ret[k] = (typename channel_type<P>::type)(in_color_[k] * t +
                                                out_color_[k] * (1 - t));
    return ret;
  }

private:
  double get_num_iter(point<double> const &p) const {
    point<double> Z(0, 0);
    for (int i = 0; i < MAX_ITER; ++i) {
      Z = point<double>(Z.x * Z.x - Z.y * Z.y + p.x, 2 * Z.x * Z.y + p.y);
      if (Z.x * Z.x + Z.y * Z.y > 4)
        return i / (double)MAX_ITER;
    }
    return 0;
  }
};

template <typename Pixel> struct mandel_view {
  using deref_t = mandelbrot_fn<Pixel>;
  using locator_t = virtual_2d_locator<deref_t, false>;
  using my_virt_view_t = image_view<locator_t>;
  using type = my_virt_view_t;
};

template <typename Pixel>
auto create_mandel_view(unsigned int width, unsigned int height,
                        Pixel const &in, Pixel const &out) ->
    typename mandel_view<Pixel>::type {
  using view_t = typename mandel_view<Pixel>::type;
  using deref_t = typename mandel_view<Pixel>::deref_t;
  using locator_t = typename mandel_view<Pixel>::locator_t;

  point_t dims(width, height);
  return view_t(
      dims, locator_t(point_t(0, 0), point_t(1, 1), deref_t(dims, in, out)));
}

#endif // BOOST_GIL_IO_TEST_MANDEL_HPP
