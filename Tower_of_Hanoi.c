#include<stdio.h>
void towers(int, char, char, char);
int main()
{
    int num;
    printf("Enter the number of Disks: ");
    scanf("%d",&num);
    towers(num, 'A','C','B');
}
void towers(int n, char frompeg, char auxpeg, char topeg)
{
    if(n==1)
    printf("Move disk 1 from %c to %c\n",frompeg, topeg);
    else{
        towers(n-1,frompeg,auxpeg,topeg);
        printf("Move disk %d from %c to %c\n",n,frompeg,topeg);
        towers(n-1,topeg,auxpeg,frompeg);
    }
}