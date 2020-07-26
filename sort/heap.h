/// \file heap.h
/// \brief heap sort
/// \author juhyun-nam

#ifndef SORT_HEAP_H_
#define SORT_HEAP_H_
#include <algorithm>
#include <iterator>

namespace ma {

template <
    typename It,
    typename Comp = std::less<typename std::iterator_traits<It>::value_type>>
inline void HeapSort(It first, It last, Comp comp = Comp()) {
  // make heap
  // void Heapify(first, last, comp);
  std::make_heap(first, last, comp);
  for (auto end = last; first != end; --end) {
    std::pop_heap(first, end);
  }
}
}  // namespace ma

#endif  // SORT_HEAP_H_
