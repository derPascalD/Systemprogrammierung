#include <stdio.h>
#include "zoo.h"

int main() {

    float durchschnitt = calculate_average_age();
    printf("%.2f\n\n", durchschnitt);

    more_food();
    print_zoo();
    return 0;
}