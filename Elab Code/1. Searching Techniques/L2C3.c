#include <stdio.h>
#include <stdbool.h>
int main()
{
    char MOJO[] = "MOJO";
    char arr[4][100];
    for(int i = 0; i < 4; i++) {
        scanf("%s", arr[i]);
        // printf("%s\n", arr[i]);
    }
    for(int i = 0; i < 4; i++){
        for(int j= 0; j < 4; j++){
            int k = 0;
            bool found = 0;
            while(arr[j][k] != '\0'){
                if(MOJO[i] == arr[i][k]){
                    printf("%c: %d,%d\n", MOJO[i], j, k);
                    found = 1;
                    break;
                }
                k++;
            }
            if(found) break;
        }
    }
	return 0;
}