/// \file insertion.h
/// \brief insertion sort
/// \author juhyun-nam

#ifndef SORT_INSERTION_H_
#define SORT_INSERTION_H_

#include "sort/sort_base.h"

namespace mca {
namespace detail {

template <typename It, typename Comp>
inline void InsertionSort(It begin, It end, Comp comp) {
  static_assert(IsBidirectionalIterator<It>::value,
                "iterator must be bidirectional");

  if (begin == end) {
    return;
  }
  auto pivot = begin;
  while (true) {
    auto lt_l = pivot;
    ++pivot;
    auto lt_r = pivot;
    if (lt_r == end) {
      break;
    }
    while (lt_r != begin) {
      if (comp(*lt_l, *lt_r) || *lt_l == *lt_r) {
        break;
      } else {
        std::iter_swap(lt_l, lt_r);
        --lt_l;
        --lt_r;
      }
    }
  }
}

}  // namespace detail

template <typename It>
inline void Sort(Insertion, It begin, It end) {
  detail::InsertionSort(
      begin, end, std::less<typename std::iterator_traits<It>::value_type>{});
}
template <typename It, typename Comp>
inline void Sort(Insertion, It begin, It end, Comp comp) {
  detail::InsertionSort(begin, end, comp);
}

}  // namespace mca

#endif  // SORT_INSERTION_H_
