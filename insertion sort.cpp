#include <iostream>
using namespace std;

void insertionSort(int arr[], int arrSize)
{
    int curr, pos;
    for (int i = 1; i < arrSize; i++)
    {
        curr = arr[i];
        pos = i;
        while (pos > 0 && curr < arr[pos-1])
        {
            arr[pos] = arr[pos-1];
            pos = pos - 1;
        }
        arr[pos] = curr;
    }
}

int main()
{
    int arr[] = {5, 1, 1, 3, 3, 2};
    int arrSize = sizeof(arr) / sizeof(int);

    insertionSort(arr, arrSize);
    for (int i = 0; i < arrSize; i++)
    {
        cout << arr[i] << " ";
    }
}
