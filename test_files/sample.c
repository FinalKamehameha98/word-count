#include <stdio.h>

int main(){
    int j = 1;
    for(int i = 0; i < 100; i++){
        printf("%d + %d = %d\n", i, j, i+j);
        printf("%d * %d = %d\n", i, j, i*j);
    }
    return 0;
}
