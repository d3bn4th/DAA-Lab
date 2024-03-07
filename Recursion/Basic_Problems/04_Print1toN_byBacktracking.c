// print the numbers from 1 to N using Backtracking 
#include<stdio.h>

void fun(int i, int n) {
    if(i < 1) return;
    fun(i-1, n);
    printf("%d \n",i); // 1 2 3 ... N-1 N  
}

int main(){
    int n;
    scanf("%d", &n);
    fun(n, n);
    return 0;
}