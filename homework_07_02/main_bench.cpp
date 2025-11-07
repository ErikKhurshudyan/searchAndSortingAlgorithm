#include "headers/function.hpp"
#include <benchmark/benchmark.h>
#include <vector>
#include <list>
#include <deque>

const int SIZE = 1 << 4;

static void BM_VectorSelectionSort(benchmark::State& state) {
    std::vector<int> v(SIZE);
    for (int i = 0; i < SIZE; ++i) v[i] = SIZE - i - 1;

    while (state.KeepRunning()) {
        selectionSort(v.begin(), v.end());
        benchmark::DoNotOptimize(v);
    }
}
BENCHMARK(BM_VectorSelectionSort);

static void BM_ListSelectionSort(benchmark::State& state) {
    std::list<int> l;
    for (int i = 0; i < SIZE; ++i) l.push_back(SIZE - i - 1);

    while (state.KeepRunning()) {
        selectionSort(l.begin(), l.end());
        benchmark::DoNotOptimize(l);
    }
}
BENCHMARK(BM_ListSelectionSort);

static void BM_DequeSelectionSort(benchmark::State& state) {
    std::deque<int> d(SIZE);
    for (int i = 0; i < SIZE; ++i) d[i] = SIZE - i - 1;

    while (state.KeepRunning()) {
        selectionSort(d.begin(), d.end());
        benchmark::DoNotOptimize(d);
    }
}
BENCHMARK(BM_DequeSelectionSort);

BENCHMARK_MAIN();

