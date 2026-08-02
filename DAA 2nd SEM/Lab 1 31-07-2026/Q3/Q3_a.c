#include <stdio.h>

void bubbleSort(int arr[], int n)
{
    int i,j,temp,swapped;

    for(i=0;i<n-1;i++)
    {
        swapped=0;

        for(j=0;j<n-i-1;j++)
        {
            if(arr[j]>arr[j+1])
            {
                temp=arr[j];
                arr[j]=arr[j+1];
                arr[j+1]=temp;
                swapped=1;
            }
        }

        if(!swapped)
            break;
    }
}

int main()
{
    int arr[]={5,1,4,2,8};
    int n=5;

    bubbleSort(arr,n);

    for(int i=0;i<n;i++)
        printf("%d ",arr[i]);

    return 0;
}

/*
-> bubble sort works as per its name (literally !)
-> starting from the first element (pivot), with the pivot progressing ahead by one per iteration, the element that is largest in the elements preceding the current pivot is swapped ahead.
-> in short, the largest element is bubbled up
-> to get a decreasing order, the swap can be made with the lowest one from the elements preceding the pivot.
-> the algorithm fails when the array is almost or fully sorted.
*/