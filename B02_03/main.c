#include <stdio.h>
#include "zoo.h"
#include "string.h"

int main()
{
    float durchschnitt;
    durchschnitt = calculate_average_age();
    printf("%.2f\n\n", durchschnitt);
    print_zoo();
    printf("\n");
    more_food();
    print_zoo();
    return 0;
}