#include <stdio.h>
int partition(int arr[], int first, int last)
{
    int mid = first, pivot = arr[first];
    for (int sweep = first + 1; sweep <= last; sweep++)
        if (arr[sweep] < pivot)
        {
            int t = arr[sweep];
            arr[sweep] = arr[mid + 1];
            arr[mid + 1] = t;
            mid++;
        }
    arr[first] = arr[mid];
    arr[mid] = pivot;
    return mid;
}
/* quickSort with an explicit stack of (first,last) pairs instead of recursion */
void quickSortIter(int arr[], int n)
{
    int stackF[64], stackL[64], top = 0;
    stackF[top] = 0;
    stackL[top] = n - 1;
    top++;
    while (top > 0)
    {
        top--;
        int first = stackF[top], last = stackL[top];
        if (last <= first)
            continue;
        int mid = partition(arr, first, last);
        stackF[top] = first;
        stackL[top] = mid - 1;
        top++;
        stackF[top] = mid + 1;
        stackL[top] = last;
        top++;
    }
}
int main(void)
{
    int a[] = {15, -4, 18, 22, 0, 5, 49, 42, 25, 23, -8, -3, 6};
    quickSortIter(a, 13);
    for (int i = 0; i < 13; i++)
        printf("%d ", a[i]);
    printf("\n");
    return 0;
}
