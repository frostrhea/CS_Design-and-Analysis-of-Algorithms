#include <algorithm>
#include <chrono>
#include <iostream>
#include <iomanip>
#include "linear algo test.cpp"
using namespace std;
using namespace std::chrono;

int main()

{
    int value;
    cout << "Enter the array size number: ";
    cin >> value;
    int *arr = new int[value];
    // int arr[value];
    // int n = sizeof(arr) / sizeof(int);

    for (int r = 0; r < value; r++)
        arr[r] = rand() % 10000;

    cout.setf(ios::fixed, ios::floatfield);
    cout.precision(12);

    //----------------------------------------------------------------------
    auto start = high_resolution_clock::now();
    binSort(arr, n);
    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<nanoseconds>(stop - start) * 1e-6;
    cout << "Time taken (binSort): "
         << duration.count() << " milliseconds" << endl;

    //----------------------------------------------------------------------
    auto start1 = high_resolution_clock::now();
    countingSort(arr, n);
    auto stop1 = high_resolution_clock::now();
    auto duration1 = duration_cast<nanoseconds>(stop1 - start1) * 1e-6;

    cout << "Time taken (countingSort): "
         << duration1.count() << " milliseconds" << endl;

    //---------------------------------------------------------------------
    auto start2 = high_resolution_clock::now();
    radixSort(arr, n);
    auto stop2 = high_resolution_clock::now();
    auto duration2 = duration_cast<nanoseconds>(stop2 - start2) * 1e-6;

    cout << "Time taken (radixSort): "
         << duration2.count() << " milliseconds" << endl;

    //---------------------------------------------------------------------
    delete[] arr;
    return 0;
}
