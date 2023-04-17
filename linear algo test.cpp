#include <iostream>
#include <algorithm>
using namespace std;

void binSort(int arr[], int n)
{
    int max = arr[0], min = arr[0];
    for (int i = 1; i < n; i++)
    {
        if (arr[i] > max)
        {
            max = arr[i];
        }
        if (arr[i] < min)
        {
            min = arr[i];
        }
    }

    int range = max - min + 1;
    int *count = new int[range];
    for (int i = 0; i < range; i++)
    {
        count[i] = 0;
    }

    for (int i = 0; i < n; i++)
    {
        count[arr[i] - min]++;
    }

    for (int i = 0, j = 0; i < range; i++)
    {
        while (count[i] > 0)
        {
            arr[j++] = i + min;
            count[i]--;
        }
    }
}
//----------------------------------------------------------------

void countingSort(int arr[], int n)
{
    // Find the maximum element in the array
    int maxElement = *max_element(arr, arr + n);

    // Create a count array with size equal to the maximum element in the array
    int *count = new int[maxElement + 1]();

    // Fill the count array with the frequency of each element in the array
    for (int i = 0; i < n; i++)
    {
        count[arr[i]]++;
    }

    // Modify the count array to store the prefix sum of the frequency array
    for (int i = 1; i <= maxElement; i++)
    {
        count[i] += count[i - 1];
    }

    // Create a temporary array to store the sorted output
    int *temp = new int[n];

    // Sort the array by iterating through it from right to left
    for (int i = n - 1; i >= 0; i--)
    {
        temp[count[arr[i]] - 1] = arr[i];
        count[arr[i]]--;
    }

    // Copy the sorted array from the temporary array to the original array
    for (int i = 0; i < n; i++)
    {
        arr[i] = temp[i];
    }

    // Free the dynamically allocated memory
    delete[] temp;
}

//----------------------------------------------------------------

// A utility function to get maximum value in arr[]
int getMax(int arr[], int n)
{
    int mx = arr[0];
    for (int i = 1; i < n; i++)
        if (arr[i] > mx)
            mx = arr[i];
    return mx;
}

// A function to do counting sort of arr[] according to
// the digit represented by exp.
void countSort(int arr[], int n, int exp)
{
    int *output = new int[n]; // output array
    int i, count[10] = {0};

    // Store count of occurrences in count[]
    for (i = 0; i < n; i++)
        count[(arr[i] / exp) % 10]++;

    // Change count[i] so that count[i] now contains actual
    //  position of this digit in output[]
    for (i = 1; i < 10; i++)
        count[i] += count[i - 1];

    // Build the output array
    for (i = n - 1; i >= 0; i--)
    {
        output[count[(arr[i] / exp) % 10] - 1] = arr[i];
        count[(arr[i] / exp) % 10]--;
    }

    // Copy the output array to arr[], so that arr[] now
    // contains sorted numbers according to current digit
    for (i = 0; i < n; i++)
        arr[i] = output[i];
}

// The main function to that sorts arr[] of size n using
// Radix Sort
void radixSort(int arr[], int n)
{
    // Find the maximum number to know number of digits
    int m = getMax(arr, n);

    // Do counting sort for every digit. Note that instead
    // of passing digit number, exp is passed. exp is 10^i
    // where i is current digit number
    for (int exp = 1; m / exp > 0; exp *= 10)
        countSort(arr, n, exp);
}

//----------------------------------------------------------------
/*
int main()
{
    int arr[] = {5, 2, 3, 1, 5, 2, 3, 1};
    int n = sizeof(arr) / sizeof(arr[0]);

    binSort(arr, n);
    cout << "Sorted array is BIN: ";
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }

    countingSort(arr, n);
    cout << "Sorted array is COUNT : ";
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }

    radixSort(arr, n);
    cout << "Sorted array is RADIX : ";
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    return 0;
}
*/