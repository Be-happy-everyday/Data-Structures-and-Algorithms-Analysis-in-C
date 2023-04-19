#include<iostream>

using namespace std;

void CountingSort(int* arr, int n , int div);

int main()
{
    int arr[5] = {22,123,121,200,205};
    int mx = arr[0];
    for(int i = 1; i < 5; i++)
    {
        if(mx < arr[i]) mx = arr[i];
    }

    int i = 1;
    int q = mx / i;

    while (q > 0)
    {
        CountingSort(arr,5,i);
        i = i * 10;
        q = mx / i;
    }
    for(int i = 0 ; i < 5; i++) cout << arr[i] << endl;

    return 0;
}

void CountingSort(int* arr, int n , int div)
{
    int cnt[10] = {0};
    int* tempArray = new int[n]{};
    
    for(int i = 0; i < n; i++)
    {
        int lastnum = (arr[i]/div)%10;
        cnt[lastnum] = cnt[lastnum] + 1;
    }
    for(int i = 1 ; i < 10 ; i++) cnt[i] = cnt[i-1] + cnt[i];

    for (int i = n-1; i >= 0; i--)
    {
        int lastnum = (arr[i]/div)%10;
        tempArray[(cnt[lastnum]-1)] = arr[i];
        cnt[lastnum] -= 1;
    }

    for(int i = 0; i < n ; i++) arr[i] = tempArray[i];

    delete[] tempArray;
}