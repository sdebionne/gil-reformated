//
// Copyright 2005-2007 Adobe Systems Incorporated
//
// Distributed under the Boost Software License, Version 1.0
// See accompanying file LICENSE_1_0.txt or copy at
// http://www.boost.org/LICENSE_1_0.txt
//
#ifndef BOOST_GIL_CONCEPTS_PIXEL_BASED_HPP
#define BOOST_GIL_CONCEPTS_PIXEL_BASED_HPP

#include <boost/gil/concepts/basic.hpp>
#include <boost/gil/concepts/channel.hpp>
#include <boost/gil/concepts/color.hpp>
#include <boost/gil/concepts/concept_check.hpp>
#include <boost/gil/concepts/fwd.hpp>

#include <cstddef>

#if BOOST_GCC >= 40700
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wunused-local-typedefs"
#endif

namespace boost {
namespace gil {

/// \ingroup PixelBasedConcept
/// \brief Concept for all pixel-based GIL constructs, such as pixels,
/// iterators, locators, views and images whose value type is a pixel. \code
/// concept PixelBasedConcept<typename T>
/// {
///     typename color_space_type<T>;
///         where Metafunction<color_space_type<T> >;
///         where ColorSpaceConcept<color_space_type<T>::type>;
///     typename channel_mapping_type<T>;
///         where Metafunction<channel_mapping_type<T> >;
///         where ChannelMappingConcept<channel_mapping_type<T>::type>;
///     typename is_planar<T>;
///         where Metafunction<is_planar<T> >;
///         where SameType<is_planar<T>::type, bool>;
/// };
/// \endcode
template <typename P> struct PixelBasedConcept {
  void constraints() {
    typedef typename color_space_type<P>::type color_space_t;
    gil_function_requires<ColorSpaceConcept<color_space_t>>();
    typedef typename channel_mapping_type<P>::type channel_mapping_t;
    gil_function_requires<ChannelMappingConcept<channel_mapping_t>>();

    static const bool planar = is_planar<P>::type::value;
    ignore_unused_variable_warning(planar);

    // This is not part of the concept, but should still work
    static const std::size_t nc = num_channels<P>::value;
    ignore_unused_variable_warning(nc);
  }
};

/// \brief Concept for homogeneous pixel-based GIL constructs
/// \ingroup PixelBasedConcept
/// \code
/// concept HomogeneousPixelBasedConcept<PixelBasedConcept T>
/// {
///     typename channel_type<T>;
///         where Metafunction<channel_type<T>>;
///         where ChannelConcept<channel_type<T>::type>;
/// };
/// \endcode
template <typename P> struct HomogeneousPixelBasedConcept {
  void constraints() {
    gil_function_requires<PixelBasedConcept<P>>();
    typedef typename channel_type<P>::type channel_t;
    gil_function_requires<ChannelConcept<channel_t>>();
  }
};

} // namespace gil
} // namespace boost

#if BOOST_GCC >= 40700
#pragma GCC diagnostic pop
#endif

#endif