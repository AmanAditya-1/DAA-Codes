#include <bits/stdc++.h>
using namespace std;

int cnt=0; //Defining a global variable for counting the number of comparisions

void minmax(int arr[], int l, int h, int &min, int &max)
{
    if (l == h) //if array has only one element.
    {
        if (min > arr[l])
            min = arr[l];
        if (max < arr[l])
            max = arr[l];

        return;
    }
    else if (h - l == 1) // if array has two elements.
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
        cnt++; //iif there are 2 elements in subarray then there will be only one comparision
        return;
    }
    else //if array has more than two elements.
    {
        cnt+=2;// if more than two elements in array than there will be 2 comparisions.
        int mid = (l + h) / 2;
        if(mid%2==0) //the division of subarray will be two parts each having even number of elements.
        {
            mid++;
        }
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
    cout<<"number of comparisions= "<<cnt<<endl;
    return 0;
}