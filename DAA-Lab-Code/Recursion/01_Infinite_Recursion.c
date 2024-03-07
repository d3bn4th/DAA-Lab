#include<stdio.h>
#include<unistd.h>

int cnt = 0;
void fun() {
    printf("%d ", cnt++);
    sleep(1);
    fun();
}

int main(){
    
    fun();
    return 0;
}


