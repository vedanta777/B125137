#include <stdio.h>

void bubbleSort(int arr[], int n)
{
    int i,j,temp;

    for(i=0;i<n-1;i++)
    {
        for(j=0;j<n-i-1;j++)
        {
            if(arr[j]>arr[j+1])
            {
                temp=arr[j];
                arr[j]=arr[j+1];
                arr[j+1]=temp;
            }
        }
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
-> a pass  variable is used which increases by 1 in case there's a swap.
-> the pass variable is set to zero at the end of every iteration.
-> if at the end of an iteration the pass variable is zero then it means that the array is sorted, and hence the loop is immediately terminated.
*/