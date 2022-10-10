#include <bits/stdc++.h>
using namespace std;

int partition(int arr[], int p, int q)
{
    int pi = arr[p]; // initiliazing and defining the pivot.
    int i = p, j = q;
    // checking while i is less than j then everytime i<j we will swap than elements present at i and j.
    while (i < j)
    {
        while (arr[i] <= arr[p])
        {
            i++;
        }
        while (arr[j] > arr[p])
        {
            j--;
        }
        if (i < j)
        {
            swap(arr[i], arr[j]);
        }
    }
    // and if i is greater than q than we will swap the element at index with pivot element.
    swap(arr[j], arr[p]);
    // returing the new index of the pivot to the quicksort function.
    return j;
}

void quicksort(int arr[], int p, int q)
{
    if (p < q) // check if the array has more than one element.
    {
        int loc = partition(arr, p, q); // we will get the new index of the pivot after the pivot function is executed.
        // next two quicksort functions are applied for two subarrays formed on the left and right of the pivot.
        quicksort(arr, p, loc - 1);
        quicksort(arr, loc + 1, q);
    }
}

int main()
{
    int n;
    int arr[n];
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    quicksort(arr, 0, n - 1);
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    return 0;
}