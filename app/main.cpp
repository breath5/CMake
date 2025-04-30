#include <stdio.h>
#include "../libs/network/include/math.h"
//#include "sub/sub.h"
int main(void) {
    int a = 5, b = 3;
    printf("Hello, World!\n");
//    printf("sub(%d, %d) = %d\n", a, b, sub(a, b));
    printf("add(%d, %d) = %d\n", a, b, add(a, b));
    return 0;
}
