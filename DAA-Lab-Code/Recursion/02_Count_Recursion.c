#include<stdio.h>

int cnt = 0;
void fun() {
    if(cnt == 3) return;
    printf("%d \n", cnt);
    cnt++;
    fun();
}
int main() {
    fun();

    return 0;
}

/*
Output :
0
1
2 
 */