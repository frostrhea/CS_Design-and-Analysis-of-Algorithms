#include <algorithm>
#include <chrono>
#include <iostream>
#include <cstdlib>
#include <cmath>
#include <ctime>
#include "Hashing1_Guingao.cpp"
using namespace std;
using namespace std::chrono;

int main()
{
    int numKeys;
    cout << "Enter the number of keys: ";
    cin >> numKeys;

    int tableSize = ceil(numKeys * 1.3);
    // Find the next prime number for the table size
    bool isPrime = false;
    while (!isPrime)
    {
        tableSize++;
        isPrime = true;
        for (int i = 2; i <= sqrt(tableSize); i++)
        {
            if (tableSize % i == 0)
            {
                isPrime = false;
                break;
            }
        }
    }
    cout << tableSize;

    int *keys = new int[numKeys];
    int *table = new int[tableSize];
    int totalProbesL = 0;  // for linear probing
    int totalProbesQ = 0;  // for quadratic probing
    int totalProbesDH = 0; // for double hashing

    // Initialize table with -1 to indicate empty slots
    for (int i = 0; i < tableSize; i++)
    {
        table[i] = -1;
    }

    for (int i = 0; i < numKeys; i++)
    {
        keys[i] = rand();
    }

    cout.setf(ios::fixed, ios::floatfield);
    cout.precision(12);

    //----------------------------------------------------------------------
    for (int i = 0; i < tableSize; i++)
    {
        table[i] = -1;
    }

    auto start = high_resolution_clock::now();
    // Insert keys and count probes
    for (int i = 0; i < numKeys; i++)
    {
        int probesL = linearProbing(keys[i], table, tableSize);
        totalProbesL += probesL;
    }
    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<nanoseconds>(stop - start) * 1e-6;
    cout << "\nTime taken (linearProbing): "
         << duration.count() << " milliseconds" << endl;
    cout << "Total number of probes: " << totalProbesL << endl;

    //----------------------------------------------------------------------
    for (int i = 0; i < tableSize; i++)
    {
        table[i] = -1;
    }

    auto start1 = high_resolution_clock::now();
    // Insert keys and count probes
    for (int i = 0; i < numKeys; i++)
    {
        int probesQ = quadraticProbing(keys[i], table, tableSize);
        totalProbesQ += probesQ;
    }
    auto stop1 = high_resolution_clock::now();
    auto duration1 = duration_cast<nanoseconds>(stop1 - start1) * 1e-6;
    cout << "\nTime taken (quadraticProbing): "
         << duration1.count() << " milliseconds" << endl;
    cout << "Total number of probes: " << totalProbesQ << endl;

    //---------------------------------------------------------------------
    for (int i = 0; i < tableSize; i++)
    {
        table[i] = -1;
    }

    auto start2 = high_resolution_clock::now();
    // Insert keys and count probes
    for (int i = 0; i < numKeys; i++)
    {
        int probesDH = doubleHashing(keys[i], table, tableSize);
        totalProbesDH += probesDH;
    }
    auto stop2 = high_resolution_clock::now();
    auto duration2 = duration_cast<nanoseconds>(stop2 - start2) * 1e-6;
    cout << "\nTime taken (quadraticProbing): "
         << duration2.count() << " milliseconds" << endl;
    cout << "Total number of probes: " << totalProbesDH << endl;

    //---------------------------------------------------------------------
    delete[] table;
    delete[] keys;
    return 0;
}
