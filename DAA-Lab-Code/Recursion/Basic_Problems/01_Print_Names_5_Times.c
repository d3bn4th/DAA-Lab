// Print Name N(5) times

#include<stdio.h>

int cnt = 0;
void name5times(char name[]){
    if(cnt == 5) return;
    printf("%s \n", name);
    cnt++;
    name5times(name);
}

// Striver's Code
void f(int i, int n){
    if(i > n) return;
    printf("raj\n");
    f(i+1,n);
}

int main() {
    
    name5times("Arihant");
    f(1,5);
    return 0;
}