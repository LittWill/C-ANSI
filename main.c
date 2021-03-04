#include <stdio.h>
#include <locale.h>
#define PI 3.14
int main()
{
    setlocale("LC_ALL", "Portuguese");
    printf("PI = %.4f\n", PI);
    return 0;
}
