
#include "lib.h"
void print(char ***lines)
{
    printf("printfing\n");
    printf("%s", lines[0][0]);
    printf("printfing done.\n");
}

char ***ini(void)
{
    printf("in ini\n");
    char *a = malloc(2 * sizeof(char));
    a = "zx";
        printf("A done\n");
    char **b = malloc(sizeof(char*));
    b = &a;
        printf("B done\n");
    char ***c = malloc(sizeof(char**));
    c = &b;
        printf("C done. returning.\n");
    return c;
}