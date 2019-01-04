
// =================================================================================================
// This file is part of the CLBlast project. The project is licensed under Apache Version 2.0. This
// project loosely follows the Google C++ styleguide and uses a tab-size of two spaces and a max-
// width of 100 characters per line.
//
// Author(s):
//   Cedric Nugteren <www.cedricnugteren.nl>
//
// This file implements the Xdotu routine. The precision is implemented using a template argument.
//
// =================================================================================================

#ifndef CLBLAST_ROUTINES_XDOTU_H_
#define CLBLAST_ROUTINES_XDOTU_H_

#include "routines/level1/xdot.hpp"

namespace clblast {
// =================================================================================================

// See comment at top of file for a description of the class
template <typename T>
class Xdotu: public Xdot<T> {
 public:

  // Uses the regular Xdot routine
  using Xdot<T>::DoDot;

  // Constructor
  Xdotu(Queue &queue, EventPointer event, const std::vector<EventPointer>& event_wait_list = {}, const std::string &name = "DOTU");

  // Templated-precision implementation of the routine
  void DoDotu(const size_t n,
              const Buffer<T> &dot_buffer, const size_t dot_offset,
              const Buffer<T> &x_buffer, const size_t x_offset, const size_t x_inc,
              const Buffer<T> &y_buffer, const size_t y_offset, const size_t y_inc);
};

// =================================================================================================
} // namespace clblast

// CLBLAST_ROUTINES_XDOTU_H_
#endif
