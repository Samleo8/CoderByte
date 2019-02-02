#include <stdio.h>
#include <string.h>

void FirstReverse(char * str) {
    int N = strlen(str);
    for(int i=0;i<N;i++){
        printf("%c", str[N-i-1]);
    }
}

int main(void) {
    FirstReverse(gets(stdin));
    return 0;
}
