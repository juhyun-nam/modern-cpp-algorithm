/// \file insertion.h
/// \brief insertion sort
/// \author juhyun-nam

#ifndef SORT_INSERTION_H_
#define SORT_INSERTION_H_
#include <iterator>

namespace ma {

template <
    typename It,
    typename Comp = std::less<typename std::iterator_traits<It>::value_type>>
inline void InsertionSort(It first, It last, Comp comp = Comp()) {
  auto length = last - first;
  for (int i = 1; i < length; ++i) {
    auto j = i;
    while (j > 0) {
      if (!comp(*(first + j - 1), *(first + j))) {
        std::iter_swap(first + j - 1, first + j);
        --j;
      } else {
        break;
      }
    }
  }
}

}  // namespace ma

#endif  // SORT_INSERTION_H_
