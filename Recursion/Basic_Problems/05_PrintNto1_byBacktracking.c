// print the numbers from N to 1 using Backtracking 
#include<stdio.h>

void fun(int i, int n){
    if(i > n) return;
    fun(i + 1, n); // recursive call
    printf("%d \n", i);  // N N-1 N-2 ... 3 2 1
}

int main(){
    fun(1,10);
    return 0;
}