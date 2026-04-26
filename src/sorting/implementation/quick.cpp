#include "../header/quick.hpp"
#include <cstdlib>  // rand()
#include <ctime>    // time()

void swap(int &a, int &b)
{
    int temp = a;
    a = b;
    b = temp;
}

int partition(int T[], int first, int last)
{
    int pivot = T[first];
    int bottom = first;
    int top = last;

    while (true)
    {
        while (T[bottom] < pivot)
            bottom++;

        while (T[top] > pivot)
            top--;

        if (bottom >= top)
            return top;

        swap(T[bottom], T[top]);
        bottom++;
        top--;
    }
}

int randomizedPartition(int T[], int first, int last)
{
    int randomIndex = first + rand() % (last - first + 1);
    swap(T[first], T[randomIndex]); // move random pivot to front
    return partition(T, first, last);
}

void quickSortV1(int T[], int first, int last)
{
    if (first < last)
    {
        int cut = partition(T, first, last);
        quickSortV1(T, first, cut);
        quickSortV1(T, cut + 1, last);
    }
}

void quick_V1(int arr[], int n)
{
    quickSortV1(arr, 0, n - 1);
}

void insertionForQuick(int arr[], int first, int last)
{
    for (int i = first + 1; i <= last; i++)
    {
        int key = arr[i];
        int j = i - 1;

        while (j >= first && arr[j] > key)
        {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;
    }
}

void quickSortV2(int T[], int first, int last)
{
    while (first < last)
    {
        if (last - first <= 10)
        {
            insertionForQuick(T, first, last);
            return;
        }

        int cut = randomizedPartition(T, first, last);

        if (cut - first < last - cut)
        {
            quickSortV2(T, first, cut);
            first = cut + 1;
        }
        else
        {
            quickSortV2(T, cut + 1, last);
            last = cut;
        }
    }
}

void quick_V2(int arr[], int n)
{
    srand(time(0));
    quickSortV2(arr, 0, n - 1);
}