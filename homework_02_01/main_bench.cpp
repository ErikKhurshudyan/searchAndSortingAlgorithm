#include "headers/Vector.hpp"
#include "headers/List.hpp"
#include "headers/SingleList.hpp"

#include <benchmark/benchmark.h>

const int SIZE = 1 << 15; // 32768 elements

// ---- Vector ----
static void BM_Vector_LinearSearch(benchmark::State& state)
{
    Vector<int> v;
    for (int i = 0; i < SIZE; ++i)
    {
        v.push_back(i);
    }
    int key = SIZE - 1;

    for (; state.KeepRunning();)
    {
        bool found = v.linearSearch(key);
        benchmark::DoNotOptimize(found);
    }
}
BENCHMARK(BM_Vector_LinearSearch);

// ---- List ----
static void BM_List_LinearSearch(benchmark::State& state)
{
    List<int> l;
    for (int i = 0; i < SIZE; ++i)
    {
        l.push_back(i);
    }
    int key = SIZE - 1;

    for (; state.KeepRunning();)
    {
        bool found = l.linearSearch(key);
        benchmark::DoNotOptimize(found);
    }
}
BENCHMARK(BM_List_LinearSearch);

// ---- SingleList ----
static void BM_SingleList_LinearSearch(benchmark::State& state)
{
    SingleList<int> sl;
    for (int i = SIZE - 1; i >= 0; --i)
    {
        sl.push_front(i); // keep ascending order
    }
    int key = SIZE - 1;

    for (; state.KeepRunning();)
    {
        bool found = sl.linearSearch(key);
        benchmark::DoNotOptimize(found);
    }
}
BENCHMARK(BM_SingleList_LinearSearch);

BENCHMARK_MAIN();

