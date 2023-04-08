#include <algorithm>
#include <chrono>
#include <iostream>
#include <iomanip>
#include "nlogn algo test.cpp"
using namespace std;
using namespace std::chrono;


int main()

{
    int value;
    cout<<"Enter the array size number: ";
    cin>>value;
    int arr[value];
    int n = sizeof(arr) / sizeof(int);

    for(int r= 0; r <value; r++)
        arr[r]=rand()%10000;

    cout.setf(ios::fixed,ios::floatfield);
    cout.precision(12);

//----------------------------------------------------------------------
    auto start = high_resolution_clock::now();
    shellSort(arr, n);
    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<nanoseconds>(stop - start) * 1e-6;
    cout << "Time taken (shell sort): "
         << duration.count() << " milliseconds" << endl;

//----------------------------------------------------------------------
    auto start1 = high_resolution_clock::now();
    mergeSort(arr, 0, n - 1);
    auto stop1 = high_resolution_clock::now();
    auto duration1 = duration_cast<nanoseconds>(stop1 - start1) * 1e-6;

    cout << "Time taken (mergeSort): "
         << duration1.count() << " milliseconds" << endl;


//---------------------------------------------------------------------
    auto start2 = high_resolution_clock::now();
    heapSort(arr, n);
    auto stop2 = high_resolution_clock::now();
    auto duration2 = duration_cast<nanoseconds>(stop2 - start2) * 1e-6;

    cout << "Time taken (heapSort): "
         << duration2.count()<< " milliseconds" << endl;

//---------------------------------------------------------------------

    return 0;
}
