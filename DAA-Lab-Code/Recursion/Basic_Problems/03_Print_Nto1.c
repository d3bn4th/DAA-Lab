// Print Linearly from N to 1

#include<stdio.h>

void fun(int n, int i) {
    if( n < i) return;
    printf("%d ", n);
    fun(n-1, i);
}

int main(){
    fun(10, 1);
    return 0;
}

