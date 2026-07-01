
#include "lib.h"
int main(void)
{
    char ***lines = ini();
    printf("after calling ini\n");
    print(lines);
    free(**lines);
    free(*lines);
    free(lines);
    return 0;
}