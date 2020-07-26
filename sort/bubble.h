/// \file bubble.h
/// \brief bubble sort
/// \author juhyun-nam

#ifndef SORT_BUBBLE_H_
#define SORT_BUBBLE_H_
#include <functional>
#include <iterator>

namespace ma {

template <typename It,
          typename Comp = std::less_equal<typename std::iterator_traits<It>::value_type>>
inline void BubbleSort(It begin, It end, Comp comp = Comp()) {
  static_assert(std::is_base_of<std::bidirectional_iterator_tag,
                                typename std::iterator_traits<It>::iterator_category>::value,
                "iterator must be bidirectional");
  auto last = end;
  auto post = begin;
  ++post;
  for (; last != post; --last) {
    bool swapped = false;
    auto first_l = begin;
    auto first_r = post;
    for (; first_r != last; ++first_l, ++first_r) {
      if (!comp(*first_l, *first_r)) {
        std::iter_swap(first_l, first_r);
        swapped = true;
      }
    }
    if (!swapped) {
      break;
    }
  }
}

}  // namespace ma

#endif  // SORT_BUBBLE_H_
