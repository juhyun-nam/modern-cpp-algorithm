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

  SUBCASE("Bubble") {
    auto data = main_data;
    ma::BubbleSort(data.begin(), data.end());
    CHECK(std::is_sorted(data.begin(), data.end()));
  }
  SUBCASE("Selection") {
    auto data = main_data;
    ma::SelectionSort(data.begin(), data.end());
    CHECK(std::is_sorted(data.begin(), data.end()));
  }
  SUBCASE("Insertion") {
    auto data = main_data;
    ma::InsertionSort(data.begin(), data.end());
    CHECK(std::is_sorted(data.begin(), data.end()));
  }
  SUBCASE("Heap") {
    auto data = main_data;
    ma::HeapSort(data.begin(), data.end());
    CHECK(std::is_sorted(data.begin(), data.end()));
  }
  /*
  SUBCASE("Merge") {
    auto data = main_data;
    ma::MergeSort(data.begin(), data.end());
    CHECK(std::is_sorted(data.begin(), data.end()));
  }
  */
  SUBCASE("Quick") {
    auto data = main_data;
    ma::QuickSort(data.begin(), data.end());
    CHECK(std::is_sorted(data.begin(), data.end()));
  }
  SUBCASE("Shell") {
    auto data = main_data;
    ma::ShellSort(data.begin(), data.end());
    CHECK(std::is_sorted(data.begin(), data.end()));
  }
  SUBCASE("Counting") {
    auto data = main_data;
    ma::CountingSort(data.begin(), data.end(), 0, kSortLimit - 1);
    CHECK(std::is_sorted(data.begin(), data.end()));
  }
  /*
  SUBCASE("Radix") {
    auto data = main_data;
    ma::RadixSort(data.begin(), data.end(), 2);
    CHECK(std::is_sorted(data.begin(), data.end()));
  }
  */
}