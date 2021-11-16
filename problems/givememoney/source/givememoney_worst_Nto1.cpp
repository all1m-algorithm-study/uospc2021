#include <iostream>
#include "testlib.h"
 
int main(int argc, char* argv[]) {
    registerGen(argc, argv, 1);
 
    int n = atoi(argv[1]);
    printf("%d\n", n);
 
    for (int i = n; i > 0; --i) {
        printf("%d", i);
        if (i > 1) {
            printf(" ");
        }
    }
    printf("\n");
 
    return 0;
}
