#include <bits/stdc++.h>
using namespace std;

void printTheArray(int arr[], int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << arr[i];
    }
    cout << endl;
}

void generateAllBinaryStrings(int n, int arr[], int i)
{
    if (i == n)
    {
        printTheArray(arr, n);
        return;
    }
    arr[i] = 0;
    generateAllBinaryStrings(n, arr, i + 1);
    arr[i] = 1;
    generateAllBinaryStrings(n, arr, i + 1);
}

// Driver Code
int main()
{
    int n;
    cin >> n;
    int arr[n];

    // Print all binary strings
    generateAllBinaryStrings(n, arr, 0);

    return 0;
}