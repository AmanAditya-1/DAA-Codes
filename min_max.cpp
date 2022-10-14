#include <bits/stdc++.h>
using namespace std;

void minmax(int arr[], int l, int h, int &min, int &max)
{
    if (l == h)
    {
        if (min > arr[l])
            min = arr[l];
        if (max < arr[l])
            max = arr[l];

        return;
    }
    else if (h - l == 1)
    {
        if (arr[l] < arr[h])
        {
            if (arr[l] < min)
                min = arr[l];
            if (arr[h] > max)
                max = arr[h];
        }
        else
        {
            if (arr[h] < min)
                min = arr[h];
            if (arr[l] > max)
                max = arr[l];
        }
        return;
    }
    else
    {
        int mid = (l + h) / 2;
        minmax(arr, l, mid, min, max);
        minmax(arr, mid + 1, h, min, max);
    }
}

int main()
{
    int n, min = INT_MAX, max = INT_MIN;
    int arr[n];
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    minmax(arr, 0, n - 1, min, max);
    cout << "min= " << min << endl;
    cout << "max= " << max << endl;
    cout<<"number of comparisions= "<<floor(((3*n)/2)-2)<<endl;
    return 0;
}