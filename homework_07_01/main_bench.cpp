#include "headers/Vector.hpp"
#include "headers/List.hpp"
#include "headers/function.hpp"
#include <benchmark/benchmark.h>

const int SIZE = 1 << 15; // 32768 elements

static void
BM_Vector_SelectionSort(benchmark::State& state)
{
    for (; state.KeepRunning();) {
        Vector<int> v;
        for (int i = 0; i < SIZE; ++i) {
            v.push_back(SIZE - i); 
        }

        selectionSort(v);
        benchmark::DoNotOptimize(v);
    }
}
BENCHMARK(BM_Vector_SelectionSort);

static void
BM_List_SelectionSort(benchmark::State& state)
{
    for (; state.KeepRunning();) {
        List<int> lst;
        for (int i = 0; i < SIZE; ++i) {
            lst.push_back(SIZE - i);
        }

        selectionSort(lst);
        benchmark::DoNotOptimize(lst);
    }
}
BENCHMARK(BM_List_SelectionSort);

BENCHMARK_MAIN();

