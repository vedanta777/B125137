#include <stdio.h>

void toh(int n,char from,char aux,char to)
{
    if(n==1)
    {
        printf("Move disk 1 from %c to %c\n",from,to);
        return;
    }

    toh(n-1,from,to,aux);

    printf("Move disk %d from %c to %c\n",n,from,to);

    toh(n-1,aux,from,to);
}

int main()
{
    int n;

    printf("Enter number of disks: ");
    scanf("%d",&n);

    toh(n,'A','B','C');

    printf("\nTotal Moves = %d\n",(1<<n)-1);

    return 0;
}

/*
-> tower of hanoi is solved recursively by applying the function in a fashion similar to how it is solved in 3 steps for a 2 disc problem.
-> we divide the n discs into two parts - (n-1) discs at top and 1 disc at bottom
-> considering the (n-1) discs as one unit, we call the function to move them to middle
-> then, the single bottom one moves to the right
-> the function is called again to move the (n-1) discs from middle to right
-> this way by dividing the n discs into two parts, we call the function recursively to act upon the (n-1) discs
-> this way recursion solves TOH like a 3 disc problem.
*/