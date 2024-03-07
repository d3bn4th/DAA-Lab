// Print Linearly from 1 to N
#include<stdio.h>

void fun(int i, int n){
    if(i > n) return;
    printf("%d ", i);
    fun(i+1, n);
}

int main(){

    fun(1, 10);   
    
    return 0;
}