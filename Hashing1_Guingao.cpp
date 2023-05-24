#include <iostream>
using namespace std;

const int TABLE_SIZE = 17;

int hashFunction(int key, int tableSize)
{
    int hashValue = key % tableSize;
    if (hashValue < 0)
        hashValue += tableSize;
    return hashValue;
}

//----------------------------------------------------------------

int linearProbing(int key, int table[], int tableSize)
{
    int hashValue = hashFunction(key, tableSize);
    int probesL = 1;
    int i = 1;

    while (table[hashValue] != -1)
    {
        hashValue = (hashValue + i) % tableSize;
        probesL++;
    }

    table[hashValue] = key;
    return probesL;
}

//----------------------------------------------------------------

int quadraticProbing(int key, int table[], int tableSize)
{
    int hashValue = hashFunction(key, tableSize);
    int probesQ = 0;
    // int i = 1;

    if (table[hashValue] == -1)
    {
        table[hashValue] = key;
        probesQ++;
    }

    else
    {
        int j = 0;
        while (table[(hashValue + j * j) % tableSize] != -1)
        {
            j++;
            probesQ++;
        }
        table[(hashValue + j * j) % tableSize] = key;
        probesQ++;
    }

    return probesQ;
}

//----------------------------------------------------------------
int primaryHash(int key, int tableSize)
{
    int hashValue = key % tableSize;
    if (hashValue < 0)
        hashValue += tableSize;
    return hashValue;
}

int secondaryHash(int key)
{
    int hashValue = 13 - (key % 13);
    if (hashValue < 0)
        hashValue += 13;
    return hashValue;
}

int doubleHashing(int key, int table[], int tableSize)
{
    int primaryIndex = primaryHash(key, tableSize);

    if (table[primaryIndex] == -1)
    {
        table[primaryIndex] = key;
        return 1;
    }

    int secondaryIndex = secondaryHash(key);
    int probesDH = 1;

    while (table[primaryIndex] != -1)
    {
        primaryIndex = (primaryIndex + secondaryIndex) % tableSize;
        probesDH++;
    }

    table[primaryIndex] = key;
    return probesDH;
}

/*
int main()
{
    int table[TABLE_SIZE];
    int keys[] = {25, 88, 3, 38, 20, 71, 55, 56, 50, 105};
    int totalProbesL = 0;  // for linear probing
    int totalProbesQ = 0;  // for quadraticProbing table
    int totalProbesDH = 0; // for double hashing

    // Initialize table with -1 to indicate empty slots
    for (int i = 0; i < TABLE_SIZE; i++)
    {
        table[i] = -1;
    }

    // Insert keys and count probes
    for (int i = 0; i < 10; i++)
    {
        int probesL = linearProbing(keys[i], table);
        totalProbesL += probesL;
    }

    // Print final contents of the table
    cout << "LINEAR PROBING Final contents of the table:\n";
    cout << "| Slot | Contents \n";
    for (int i = 0; i < TABLE_SIZE; i++)
    {
        cout << "|  " << i << "   |   ";
        if (table[i] != -1)
        {
            cout << table[i];
        }
        cout << "      \n";
    }

    // Print total number of probes
    cout << "\nTotal number of probes: "
         << totalProbesL << endl;

    // QUADRATIC PROBING -----------------------------------------------------
    // Initialize table with -1 to indicate empty slots
    for (int i = 0; i < TABLE_SIZE; i++)
    {
        table[i] = -1;
    }

    // Insert keys and count probes
    for (int i = 0; i < 10; i++)
    {
        int probesQ = quadraticProbing(keys[i], table);
        totalProbesQ += probesQ;
    }

    // Print final contents of the table
    cout << "\n\nQUADRATIC PROBING Final contents of the table:\n";
    cout << "| Slot | Contents |\n";
    for (int i = 0; i < TABLE_SIZE; i++)
    {
        cout << "|  " << i << "   |   ";
        if (table[i] != -1)
        {
            cout << table[i];
        }
        cout << "      \n";
    }

    // Print total number of probes
    cout << "\nTotal number of probes: " << totalProbesQ << endl;

    // DOUBLE HASHING -----------------------------------------------------
    // Initialize table with -1 to indicate empty slots
    for (int i = 0; i < TABLE_SIZE; i++)
    {
        table[i] = -1;
    }

    // Insert keys and count probes
    for (int i = 0; i < 10; i++)
    {
        int probesDH = doubleHashing(keys[i], table);
        totalProbesDH += probesDH;
    }

    // Print final contents of the table
    cout << "\n\nDOUBLE HASHING Final contents of the table:\n";
    cout << "| Slot | Contents |\n";
    for (int i = 0; i < TABLE_SIZE; i++)
    {
        cout << "|  " << i << "   |   ";
        if (table[i] != -1)
        {
            cout << table[i];
        }
        cout << "      \n";
    }

    // Print total number of probes
    cout << "\nTotal number of probes: " << totalProbesDH << endl;
    return 0;
}
*/