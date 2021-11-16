#include <iostream>
#include "testlib.h"
 
int main(int argc, char* argv[]) {
    registerGen(argc, argv, 1);
 
    int n = atoi(argv[1]);
    printf("%d\n", n);
 
    for (int i = 2; i <= n; ++i) {
        printf("%d ", i);
    }
    printf("1\n");
 
    return 0;
}
