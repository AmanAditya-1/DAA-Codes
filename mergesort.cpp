#include <bits/stdc++.h>
using namespace std;

void merge(int arr[], int l, int mid, int h)
{
    // In this function we are merging the sorted array we start with the arrays having one element because they are already sorted. While merging the sorted arrays we have to do comparision in the given elements of the two arrays and then put them at the right index.

    int b[h - l + 1]; // We have created a new array to store the merged result of the two sorted arrays.
    int i = l, j = mid + 1, k = 0, x = l;

    while (i <= mid && j <= h) // Here we are comaparing the elements of the two sorted arrays.
    {
        if (arr[i] < arr[j])
        {
            b[k++] = arr[i++];
        }
        else
        {
            b[k++] = arr[j++];
        }
    }

    // Both of loops shown below are taken to confirm that if after comparison any of the elements are remaining in any array they will be copied in the final new array.
    while (i <= mid)
    {
        b[k++] = arr[i++];
    }
    while (j <= h)
    {
        b[k++] = arr[j++];
    }
    // Here we are copying the data of the new formed array to the original array at the right index.That's why we are intializing k=0 and x=l.
    for (k = 0, x = l; k < h - l + 1; k++, x++)
    {
        arr[x] = b[k];
    }
}

void mergesort(int arr[], int l, int h)
{
    // In this process we are dividing the array using the mid index untill each of the subarray has only one element. For e.g.:

    //                     9 3 7 5 6 4 8 2

    //         9 3 7 5                        6 4 8 2

    //     9 3       7 5                   6 4       8 2

    // 9   3           7   5           6   4          8   2
    if (l < h)
    {
        int mid = (l + h) / 2;
        mergesort(arr, l, mid);
        mergesort(arr, mid + 1, h);
        merge(arr, l, mid, h);
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
    mergesort(arr, 0, n - 1);
    cout << "Sorted array is : ";
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    return 0;
}