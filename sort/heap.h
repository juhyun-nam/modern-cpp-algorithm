/// \file heap.h
/// \brief heap sort
/// \author juhyun-nam

#ifndef SORT_HEAP_H_
#define SORT_HEAP_H_
#include <algorithm>
#include <iterator>

namespace mca {
namespace detail {

template <
    typename It,
    typename Comp = std::less<typename std::iterator_traits<It>::value_type>>
inline void HeapSort(It first, It last, Comp comp = Comp()) {
  static_assert(IsRandomAccessIterator<It>::value, "iterator must be random access");
  // make heap
  // void Heapify(first, last, comp);
  std::make_heap(first, last, comp);
  for (auto end = last; first != end; --end) {
    std::pop_heap(first, end);
  }
}
}  // namespace detail
template <typename It>
inline void Sort(Heap, It begin, It end) {
  detail::HeapSort(begin, end,
                   std::less<typename std::iterator_traits<It>::value_type>{});
}

template <typename It, typename Comp>
inline void Sort(Heap, It begin, It end, Comp comp) {
  detail::HeapSort(begin, end, comp);
}

}  // namespace mca

#endif  // SORT_HEAP_H_
