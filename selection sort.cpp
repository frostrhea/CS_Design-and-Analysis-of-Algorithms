#include <iostream>
using namespace std;

void selectionSort(int arr[], int arraySize)
{
    int minValue, index, i , j;
    int last = arraySize-1;
    for (i = 0; i < last; ++i)
    {
        minValue = arr[i];
        index = i;
        for (j = i+1; j < arraySize; ++j)
        {
            if (arr[j] < minValue)
            {
                minValue = arr[j];
                index = j;
            }
        }
        arr[index] = arr[i];
        arr[i] = minValue;
    }
}

int main()
{
    int arr[] = {5, 2, 1, 1, 3};
    int arraySize = sizeof(arr)/sizeof(int);

    selectionSort(arr, arraySize);
    for(int i = 0 ; i<arraySize; i++)
    {
                cout << arr[i] << " ";
    }
}
