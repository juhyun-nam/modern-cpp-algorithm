/// \file counting.h
/// \brief counting sort
/// \author juhyun-nam

#ifndef SORT_COUNTING_H_
#define SORT_COUNTING_H_
#include <iterator>
#include <vector>

namespace ma {

template <typename It>
inline void CountingSort(It first,
                         It last,
                         typename std::iterator_traits<It>::value_type min,
                         typename std::iterator_traits<It>::value_type max) {
  using value_t = typename std::iterator_traits<It>::value_type;
  std::vector<value_t> data(first, last);
  std::vector<value_t> counts(max - min + 1, 0);
  for (auto it = first; it != last; ++it) {
    ++counts[(*it) - min];
  }
  for (auto i = 1u; i < counts.size(); ++i) {
    counts[i] += counts[i - 1];
  }
  for (auto v : data) {
    *(first + counts[v - min] - 1) = v;
    --counts[v - min];
  }
}

}  // namespace ma

#endif  // SORT_COUNTING_H_
