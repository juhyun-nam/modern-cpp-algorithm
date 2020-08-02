/// \file bubble.h
/// \brief bubble sort
/// \author juhyun-nam

#ifndef SORT_BUBBLE_H_
#define SORT_BUBBLE_H_

#include "sort/sort_base.h"

namespace mca {
namespace detail {

template <typename It, typename Comp>
inline void BubbleSort(It begin, It end, Comp comp) {
  static_assert(IsForwardIterator<It>::value, "iterator must be forward");

  auto post = begin;
  ++post;
  auto last = end;
  while (true) {
    bool swapped = false;
    auto it_l = begin;
    auto it_r = post;

    for (; it_r != end; ++it_l, ++it_r) {
      if (!(comp(*it_l, *it_r) || *it_l == *it_r)) {
        std::iter_swap(it_l, it_r);
        swapped = true;
      }
    }
    if (!swapped) {
      break;
    }
    last = it_l;
  }
}

}  // namespace detail

template <typename It>
inline void Sort(Bubble, It begin, It end) {
  detail::BubbleSort(
      begin, end, std::less<typename std::iterator_traits<It>::value_type>{});
}
template <typename It, typename Comp>
inline void Sort(Bubble, It begin, It end, Comp comp) {
  detail::BubbleSort(begin, end, comp);
}
}  // namespace mca

#endif  // SORT_BUBBLE_H_
