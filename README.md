![Boost Generic Image Library (GIL)](https://raw.githubusercontent.com/boostorg/gil/develop/doc/_static/gil.png)

[![Licence](https://img.shields.io/badge/license-boost-4480cc.png)](http://www.boost.org/LICENSE_1_0.txt)
[![Documentation](https://img.shields.io/badge/gil-documentation-4480cc.png)](http://boostorg.github.com/gil/)
[![Wiki](https://img.shields.io/badge/gil-wiki-4480cc.png)](https://github.com/boostorg/gil/wiki)
[![Mailing List](https://img.shields.io/badge/gil-mailing%20list-4eb899.png)](https://lists.boost.org/mailman/listinfo.cgi/boost-gil)
[![Gitter](https://img.shields.io/badge/gil-chat%20on%20gitter-4eb899.png)](https://gitter.im/boostorg/gil)

 Branch     | Travis (gcc/clang) | AppVeyor (VS2017) | CircleCI (gcc/clang) | Regression
------------|--------------------|-------------------|----------------------|-----------
**develop** | [![Travis](https://travis-ci.org/boostorg/gil.svg?branch=develop)](https://travis-ci.org/boostorg/gil) | [![AppVeyor](https://ci.appveyor.com/api/projects/status/w4k19d8io2af168h/branch/develop?svg=true)](https://ci.appveyor.com/project/stefanseefeld/gil/branch/develop) | [![CircleCI](https://circleci.com/gh/boostorg/gil/tree/develop.svg?style=shield)](https://circleci.com/gh/boostorg/workflows/gil/tree/develop) | [![gil](https://img.shields.io/badge/gil-develop-4480cc.png)](http://www.boost.org/development/tests/develop/developer/gil.html)
**master**  | [![Travis](https://travis-ci.org/boostorg/gil.svg?branch=master)](https://travis-ci.org/boostorg/gil)  | [![AppVeyor](https://ci.appveyor.com/api/projects/status/w4k19d8io2af168h?svg=true)](https://ci.appveyor.com/project/stefanseefeld/gil/branch/master) | [![CircleCI](https://circleci.com/gh/boostorg/gil/tree/master.svg?style=shield)](https://circleci.com/gh/boostorg/workflows/gil/tree/master) | [![gil](https://img.shields.io/badge/gil-master-4480cc.png)](http://www.boost.org/development/tests/master/developer/gil.html)

# Boost.GIL

- [Introduction](#introduction)
- [Documentation](#documentation)
- [Requirements](#requirements)
- [Branches](#branches)
- [Community](#community)
- [Contributing](#contributing-we-need-your-help)
- [License](#license)

## Introduction

Boost.GIL is a part of the [Boost C++ Libraries](http://github.com/boostorg).

The Boost Generic Image Library (GIL) is a C++ library that abstracts image
representations from algorithms and allows writing code that can work on a
variety of images with performance similar to hand-writing for a specific image type.

## Documentation

- Latest release: https://boost.org/libs/gil
- Development: http://boostorg.github.io/gil/

## Requirements

**NOTE:** The library source code is currently being modernized for C++11.

The Boost Generic Image Library (GIL) requires:

- C++11 compiler
- Boost header-only libraries

Optionally, in order to [build and run tests](#contributing-we-need-your-help) and examples

- Boost.Filesystem
- Boost.Test

## Branches

The official repository contains the following branches:

* [**master**](https://github.com/boostorg/gil/tree/master) This
  holds the most recent snapshot with code that is known to be stable.

* [**develop**](https://github.com/boostorg/gil/tree/develop) This
  holds the most recent snapshot. It may contain unstable code.

## Community

There is number of communication channels to ask questions and discuss Boost.GIL issues:

- Mailing list [boost-gil](https://lists.boost.org/mailman/listinfo.cgi/boost-gil) ([archive](https://lists.boost.org/boost-gil/)) as well as official Boost lists, [boost-users](https://lists.boost.org/mailman/listinfo.cgi/boost-users) and
[boost](https://lists.boost.org/mailman/listinfo.cgi/boost).
- Gitter chat room [boostorg//gil](https://gitter.im/boostorg/gil).
- [cpplang.slack.com](https://cpplang.slack.com) chat room [#boost](https://cpplang.slack.com/messages/C27KZLB0X/).
- IRC channel [#boost](irc://chat.freenode.net/#osgeo-geos) on FreeNode.
- You can also ask questions via GitHub issue.


## Contributing (We Need Your Help!)

If you would like to contribute to Boost.GIL, help us improve the library
and maintain high quality, there is number of ways to do it.

If you would like to test the library, contribute new feature or a bug fix,
see the [CONTRIBUTING.md](https://github.com/boostorg/gil/blob/develop/CONTRIBUTING.md)
where the whole development infrastructure and the contributing workflow is explained in details.

You may consider performing code reviews on active
[pull requests](https://github.com/boostorg/gil/pulls) or help
with solving reported issues, especially those labelled with:

- [status/need-help](https://github.com/boostorg/gil/labels/status%2Fneed-help)
- [status/need-feedback](https://github.com/boostorg/gil/labels/status%2Fneed-feedback)
- [need-minimal-example ](https://github.com/boostorg/gil/labels/status%2Fneed-minimal-example)

Any feedback from users and developers, even simple questions about how things work
or why they were done a certain way, carries value and can be used to improve the library.

## License

Distributed under the [Boost Software License, Version 1.0](http://www.boost.org/LICENSE_1_0.txt).
