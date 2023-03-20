#include <iostream>
#include <algorithm>
#include <chrono>
#include <iomanip>
using namespace std::chrono;
using namespace std;

void printArray(int arr[], int arrSize)
{
    int i;
    for (i = 0; i < arrSize; i++)
        cout << arr[i] << " ";
    cout << endl;
}

void slowSort(int arr[], int arrSize)
{
    while(true)
    {
        bool sorted = true;
        for (int i = 0; i < arrSize-1; i++)
        {
            if (arr[i] > arr[i+1])
            {
                sorted = false;
                break;
            }
        }

        if (sorted)
            break;

        int i = rand() % arrSize;
        //cout << " " << randIndex;
        int j= rand() % arrSize;
        //cout << " " << i;
        //cout << " " << j;
        //cout << "int: " << arr[i] << " " << arr[j] << endl;
        if (i < j && j <= i + arrSize-2 && arr[i] > arr[j])
        {
            swap(arr[i], arr[j]);

        }
    }
}


int main()
{
    /*
    int arr[]= {2, 3, 4, 1, 6, 8, 9, 0, 7, 5};
    int arrSize = sizeof(arr) / sizeof(int);
    slowSort(arr, 0, arrSize);
    printArray(arr, arrSize);
    */
    /*
    int value;
    cout<<"Enter the array size number: ";
    cin>>value;
    int *arr = new int[value]; */
    int arr[10000];
    int arrSize = sizeof(arr) / sizeof(int);

    for(int r= 0; r <arrSize; r++)
        arr[r]=rand()%10000;
    cout << "array: ";
    printArray(arr, arrSize);


    cout.setf(ios::fixed,ios::floatfield);
    cout.precision(12);

    auto start2 = high_resolution_clock::now();
    slowSort(arr, arrSize);
    cout<< "sorted: ";
    printArray(arr, arrSize);
    auto stop2 = high_resolution_clock::now();
    auto duration2 = duration_cast<nanoseconds>(stop2 - start2);

    cout << "Time taken: "
         << duration2.count() * 1e-9 << " seconds" << endl;
    //delete[] arr;

    return 0;
}
