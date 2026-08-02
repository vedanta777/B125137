#include <stdio.h>

int partitionPoint(int arr[], int n)
{
    int low=0,high=n-1;

    while(low<=high)
    {
        int mid=(low+high)/2;

        if(arr[mid]==0)
            low=mid+1;
        else
            high=mid-1;
    }

    return low;
}

int main()
{
    int arr[]={0,0,0,0,1,1,1,1};

    int n=sizeof(arr)/sizeof(arr[0]);

    int p=partitionPoint(arr,n);

    printf("Partition Point = %d\n",p);

    return 0;
}

/*
-> binary search is implemented to quickly find the first occurence of 1
-> since 0s are followed by 1s, we use binary search to find 1.
-> if the mid element is 0, then 1s must begin in the right.
-> so, in this binary search, in case of no 1 found in an iteration, binary search is applied to the right side again.
-> if 1 is found, then the function terminates and the middle variable returns the index of first occurence of 1. 
-> the algorithm works exclusively when 0s are followed by 1s.
*/