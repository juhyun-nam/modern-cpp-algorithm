#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include <algorithm>
#include <cstdlib>
#include <vector>

#include "doctest/doctest.h"
#include "sort/bubble.h"
#include "sort/counting.h"
#include "sort/heap.h"
#include "sort/insertion.h"
#include "sort/quick.h"
#include "sort/radix.h"
#include "sort/selection.h"
#include "sort/shell.h"

namespace {

template <typename TestType>
void SubCase(const TestType& type,
             const char* name,
             const std::vector<int>& main_data) {
  SUBCASE(name) {
    auto data = main_data;
    mca::Sort(type, data.begin(), data.end());
    CHECK(std::is_sorted(data.begin(), data.end()));
  }
}
}  // namespace

TEST_CASE("Sort Test") {
  std::vector<int> main_data;
  std::srand(std::time(nullptr));
  constexpr int kSortSize = 100;
  constexpr int kSortLimit = 100;
  main_data.reserve(kSortSize);
  for (int i = 0; i < kSortSize; ++i) {
    main_data.push_back(std::rand() % kSortLimit);
  }

  SUBCASE("std::sort") {
    auto data = main_data;
    std::sort(data.begin(), data.end());
    CHECK(std::is_sorted(data.begin(), data.end()));
  }

  SubCase(mca::bubble, "Bubble", main_data);
  SubCase(mca::insertion, "Insertion", main_data);

  SUBCASE("Counting") {
    mca::Counting<int> counting;
    for (auto v : main_data) {
      counting.push_back(v);
    }
    counting.sort();
    CHECK(std::is_sorted(counting.begin(), counting.end()));
  }

  SUBCASE("Selection") {
    auto data = main_data;
    mca::SelectionSort(data.begin(), data.end());
    CHECK(std::is_sorted(data.begin(), data.end()));
  }
  SUBCASE("Heap") {
    auto data = main_data;
    mca::Sort(mca::heap, data.begin(), data.end());
    CHECK(std::is_sorted(data.begin(), data.end()));
  }
  /*
  SUBCASE("Merge") {
    auto data = main_data;
    mca::MergeSort(data.begin(), data.end());
    CHECK(std::is_sorted(data.begin(), data.end()));
  }
  */
  SUBCASE("Quick") {
    auto data = main_data;
    mca::QuickSort(data.begin(), data.end());
    CHECK(std::is_sorted(data.begin(), data.end()));
  }
  SUBCASE("Shell") {
    auto data = main_data;
    mca::ShellSort(data.begin(), data.end());
    CHECK(std::is_sorted(data.begin(), data.end()));
  }
  /*
  SUBCASE("Radix") {
    auto data = main_data;
    mca::RadixSort(data.begin(), data.end(), 2);
    CHECK(std::is_sorted(data.begin(), data.end()));
  }
  */
}