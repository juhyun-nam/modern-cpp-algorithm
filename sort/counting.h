/// \file counting.h
/// \brief counting sort
/// \author juhyun-nam

#ifndef SORT_COUNTING_H_
#define SORT_COUNTING_H_

#include <type_traits>
#include <vector>

#include "sort/sort_base.h"

namespace mca {
namespace detail {

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

}  // namespace detail

template <typename T>
class Counting final {
 public:
  static_assert(std::is_integral<T>::value, "T must be integral");
  using value_type = T;
  using pointer = T*;
  using reference = T&;
  using const_pointer = const T*;
  using const_reference = const T&;
  using iterator = typename std::vector<T>::iterator;
  using const_iterator = typename std::vector<T>::const_iterator;

  void sort() {
    detail::CountingSort(data_.begin(), data_.end(), min_.first, max_.first);
  }

  void push_back(const_reference v) {
    range_update(v);
    data_.push_back(v);
  }

  void clear() {
    range_clear();
    data_.clear();
  }
  iterator begin() {
    return data_.begin();
  }
  iterator end() {
    return data_.end();
  }
  iterator begin() const {
    return data_.begin();
  }
  iterator end() const {
    return data_.cend();
  }

 private:
  void range_update(const_reference v) {
    if (!min_.second || min_.first > v) {
      min_.first = v;
      min_.second = true;
    }
    if (!max_.second || max_.first < v) {
      max_.first = v;
      max_.second = true;
    }
  }
  void range_clear() {
    min_.second = false;
    max_.second = false;
  }
  std::vector<T> data_{};
  std::pair<T, bool> min_{};
  std::pair<T, bool> max_{};
};

}  // namespace mca

#endif  // SORT_COUNTING_H_
