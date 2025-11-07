#include "headers/function.hpp"
#include <benchmark/benchmark.h>
#include <vector>
#include <list>
#include <set>
#include <deque>

const int SIZE = 1 << 15;

static void BM_VectorLinearSearch(benchmark::State& state) {
    std::vector<int> v(SIZE);
    for (int i = 0; i < SIZE; ++i) v[i] = i;

    int key = SIZE - 1;
    while (state.KeepRunning()) {
        std::vector<int>::iterator found = linearSearch(v.begin(), v.end(), key);
        benchmark::DoNotOptimize(found);
    }
}
BENCHMARK(BM_VectorLinearSearch);

static void BM_ListLinearSearch(benchmark::State& state) {
    std::list<int> l;
    for (int i = 0; i < SIZE; ++i) l.push_back(i);

    int key = SIZE - 1;
    while (state.KeepRunning()) {
        std::list<int>::iterator found = linearSearch(l.begin(), l.end(), key);
        benchmark::DoNotOptimize(found);
    }
}
BENCHMARK(BM_ListLinearSearch);

static void BM_DequeLinearSearch(benchmark::State& state) {
    std::deque<int> d(SIZE);
    for (int i = 0; i < SIZE; ++i) d[i] = i;

    int key = SIZE - 1;
    while (state.KeepRunning()) {
        std::deque<int>::iterator found = linearSearch(d.begin(), d.end(), key);
        benchmark::DoNotOptimize(found);
    }
}
BENCHMARK(BM_DequeLinearSearch);

static void BM_SetLinearSearch(benchmark::State& state) {
    std::set<int> s;
    for (int i = 0; i < SIZE; ++i) s.insert(i);

    int key = SIZE - 1;
    while (state.KeepRunning()) {
        std::set<int>::iterator found = linearSearch(s.begin(), s.end(), key);
        benchmark::DoNotOptimize(found);
    }
}
BENCHMARK(BM_SetLinearSearch);

BENCHMARK_MAIN();

