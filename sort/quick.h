/// \file quick.h
/// \brief quick sort
/// \author juhyun-nam

#ifndef SORT_QUICK_H_
#define SORT_QUICK_H_
#include <iterator>

namespace ma {

template <typename It,
          typename Comp =
              std::less_equal<typename std::iterator_traits<It>::value_type>>
inline void QuickSort(It first, It last, Comp comp = Comp()) {
  auto length = last - first;
  if (length < 2) {
    return;
  }

  auto pivot = *first;
  auto end = last;
  --end;
  auto cur = first + 1;
  while (cur < end) {
    if (comp(*cur, pivot)) {
      ++cur;
    } else {
      std::iter_swap(cur, end);
      --end;
    }
  }
  if (comp(*first, *end)) {
    --end;
  }
  std::iter_swap(first, end);

  QuickSort(first, end, comp);
  QuickSort(end + 1, last, comp);
}

}  // namespace ma

#endif  // SORT_QUICK_H_
