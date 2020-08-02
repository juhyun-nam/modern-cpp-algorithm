/// \file sort_base.h
/// \brief sort base header file
/// \author juhyun-nam

#ifndef SORT_SORT_BASE_H_
#define SORT_SORT_BASE_H_
#include <functional>
#include <iterator>

namespace mca {

struct Sort {};
struct Bubble : public Sort {};
static constexpr Bubble bubble{};
struct Heap : public Sort {};
static constexpr Heap heap{};
struct Insertion : public Sort {};
static constexpr Insertion insertion{};
struct Merge : public Sort {};
static constexpr Merge merge{};
struct Quick : public Sort {};
static constexpr Quick quick{};
struct Radix : public Sort {};
static constexpr Radix radix{};
struct Selection : public Sort {};
static constexpr Selection selection{};
struct Shell : public Sort {};
static constexpr Shell shell{};

template <typename It, typename Cat>
using IteratorCategory =
    std::is_base_of<Cat, typename std::iterator_traits<It>::iterator_category>;

template <typename It>
using IsForwardIterator = IteratorCategory<It, std::forward_iterator_tag>;

template <typename It>
using IsBidirectionalIterator =
    IteratorCategory<It, std::bidirectional_iterator_tag>;

template <typename It>
using IsRandomAccessIterator =
    IteratorCategory<It, std::random_access_iterator_tag>;

}  // namespace mca

#endif  // SORT_SORT_BASE_H_