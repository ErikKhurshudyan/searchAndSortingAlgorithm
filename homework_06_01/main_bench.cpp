#include "headers/Vector.hpp"
#include "headers/List.hpp"
#include <benchmark/benchmark.h>

const int SIZE = 1 << 15; // 32768 elements

static void BM_Vector_InsertionSort(benchmark::State& state)
{
    for (auto _ : state) {
        Vector<int> v;
        for (int i = 0; i < SIZE; ++i)
            v.push_back(SIZE - i);

        v.insertionSort();
        benchmark::DoNotOptimize(v);
    }
}
BENCHMARK(BM_Vector_InsertionSort);



static void BM_List_InsertionSort(benchmark::State& state)
{
    for (auto _ : state) {
        List<int> lst;
        for (int i = 0; i < SIZE; ++i)
            lst.push_back(SIZE - i);

        lst.insertionSort();
        benchmark::DoNotOptimize(lst);
    }
}
BENCHMARK(BM_List_InsertionSort);


BENCHMARK_MAIN();

