/// \file selection.h
/// \brief selection sort
/// \author juhyun-nam

#ifndef SORT_SELECTION_H_
#define SORT_SELECTION_H_
#include <iterator>

namespace ma {

template <
    typename It,
    typename Comp = std::less<typename std::iterator_traits<It>::value_type>>
inline void SelectionSort(It first, It last, Comp comp = Comp()) {
  auto length = last - first;
  for (int i = 0; i < length - 1; ++i) {
    auto min = first + i;
    for (int j = i + 1; j < length; ++j) {
      if (comp(*(first + j), *(min))) {
        min = first + j;
      }
    }
    std::iter_swap(first + i, min);
  }
}

}  // namespace ma

#endif  // SORT_SELECTION_H_
