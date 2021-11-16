#include <iostream>
#include "testlib.h"
 
int main(int argc, char* argv[]) {
    registerGen(argc, argv, 1);
 
    int n = atoi(argv[1]);
    printf("%d\n", n);
 
    for (int i = 1; i <= n; ++i) {
        printf("%d", i);
        if (i < n) {
            printf(" ");
        }
    }
    printf("\n");
 
    return 0;
}
