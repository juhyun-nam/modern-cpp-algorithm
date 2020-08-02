/// \file shell.h
/// \brief shell sort
/// \author juhyun-nam

#ifndef SORT_SHELL_H_
#define SORT_SHELL_H_
#include <iterator>

namespace mca {

template <
    typename It,
    typename Comp = std::less<typename std::iterator_traits<It>::value_type>>
inline void ShellSort(It first, It last, Comp comp = Comp()) {
  const auto length = last - first;
  int gap = length / 2;

  while (gap > 0) {
    for (int i = 0; i < length - gap; ++i) {
      int cur = i;
      int cur_gap = i + gap;
      while (cur >= 0) {
        if (comp(*(first + cur_gap), *(first + cur))) {
          std::iter_swap(first + cur_gap, first + cur);
        }
        cur_gap = cur;
        cur -= gap;
      }
    }
    gap /= 2;
  }
}

}  // namespace ma

#endif  // SORT_SHELL_H_
