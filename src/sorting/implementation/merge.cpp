#include "../header/merge.hpp"

void merge(int arr[], int left, int mid, int right)
{

    int size1 = mid - left + 1;
    int size2 = right - mid;

    int L[size1], R[size2];

    for (int i = 0; i < size1; i++)
        L[i] = arr[left + i];
    for (int i = 0; i < size2; i++)
        R[i] = arr[mid + 1 + i];

    int i = 0, j = 0, k = left;

    while (i < size1 && j < size2)
    {
        if (L[i] <= R[j])
            arr[k++] = L[i++];
        else
            arr[k++] = R[j++];
    }

    while (i < size1)
        arr[k++] = L[i++];
    while (j < size2)
        arr[k++] = R[j++];
}

void split(int arr[], int left, int right)
{
    if (left >= right)
        return;

    int mid = (left + right) / 2;

    split(arr, left, mid);
    split(arr, mid + 1, right);
    merge(arr, left, mid, right);
}