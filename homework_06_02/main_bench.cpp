#include "headers/function.hpp"
#include <benchmark/benchmark.h>
#include <vector>
#include <list>
#include <cstdlib>

const int SIZE = 1 << 14; // 16384

// ---- Vector ----
static void BM_Vector_InsertionSort(benchmark::State& state)
{
    for (auto _ : state) {
        std::vector<int> v(SIZE);
        for (int i = 0; i < SIZE; ++i)
            v[i] = SIZE - i; // worst-case
        insertionSort(v.begin(), v.end());
        benchmark::DoNotOptimize(v);
    }
}
BENCHMARK(BM_Vector_InsertionSort);

// ---- List ----
static void BM_List_InsertionSort(benchmark::State& state)
{
    for (auto _ : state) {
        std::list<int> lst;
        for (int i = 0; i < SIZE; ++i)
            lst.push_back(SIZE - i); // worst-case
        insertionSort(lst.begin(), lst.end());
        benchmark::DoNotOptimize(lst);
    }
}
BENCHMARK(BM_List_InsertionSort);

BENCHMARK_MAIN();

