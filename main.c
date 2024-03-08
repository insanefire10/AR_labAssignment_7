#include <stdio.h>
#include <stdlib.h>
#define ARRSIZE 9

void swap(int *a, int *b)
{
    int temp;
    temp = *a;
    *a = *b;
    *b = temp;
}

void printarr(int arr[])
{
    for(int i = 0; i < ARRSIZE; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

void bubbleSort(int arr[])
{
    int totalSwapCount = 0;
    int eachSwap[ARRSIZE] = {0};
    for(int i = 0; i < ARRSIZE - 1; i++)
    {
        for(int k = 0; k < ARRSIZE - 1; k++)
        {
            if(arr[k] > arr[k+1])
            {
                swap(&arr[k], &arr[k+1]);
                eachSwap[k]++;
                eachSwap[k+1]++;
                swap(&eachSwap[k], &eachSwap[k+1]);
                totalSwapCount++;
            }
        }
    }
    
    for(int m = 0; m < ARRSIZE; m++)
    {
        printf("%d swapped %d times\n", arr[m], eachSwap[m]);
    }
    printf("Total of %d swaps\n", totalSwapCount);
}

void selectionSort(int arr[])
{
    int totalSwapCount = 0;
    int eachSwap[ARRSIZE] = {0};
    int min = arr[0];
    int index = 0;
    int flag = 0;
    for(int i = 0; i < ARRSIZE - 1; i++)
    {
        flag = 0;
        min = arr[i];
        for(int k = i; k < ARRSIZE; k++)
        {
            if(arr[k] < min)
            {
                min = arr[k];
                index = k;
                flag = 1;
            }
        }
        if(flag)
        {
            eachSwap[i]++;
            eachSwap[index]++;
            swap(&arr[i], &arr[index]);
            swap(&eachSwap[i], &eachSwap[index]);
            totalSwapCount++;
        }

    }
    for(int m = 0; m < ARRSIZE; m++)
    {
        printf("%d swapped %d times\n", arr[m], eachSwap[m]);
    }
    printf("Total of %d swaps\n", totalSwapCount);

}



int main()
{
    int arr1s[9] = {97, 16, 45, 63, 13, 22, 7, 58, 72};
    int arr1b[9] = {97, 16, 45, 63, 13, 22, 7, 58, 72};
    int arr2s[9] = {90, 80, 70, 60, 50, 40, 30, 20, 10};
    int arr2b[9] = {90, 80, 70, 60, 50, 40, 30, 20, 10};
    printf("Bubble sort of array 1:\n");
    bubbleSort(arr1b);
    printf("\nBubble sort of array 2:\n");
    bubbleSort(arr2b);
    printf("\nSelection sort of array 1:\n");
    selectionSort(arr1s);
    printf("\nSelection sort of array 2:\n");
    selectionSort(arr2s);

}