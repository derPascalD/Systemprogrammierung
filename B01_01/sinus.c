#include "math.h"
#include "stdio.h"
#include "stdlib.h"

#define PI 3.141592654

double radian;
int counter, run = 1;

void forSchleife(void);
void whileSchleife(void);

int main() {
    forSchleife();
    printf("\n");
    whileSchleife();
    return 0;
}

void forSchleife() {
    int i;
    for (i = 0; i <= 360; i += 10) {

        /*Gradmaß in Bogenmaß umrechnen*/
        radian = ((double) i / 180) * PI;

        printf("Winkel: %3d Grad => Sinus-Funktionswert: %6.3f \n", i, sin(radian));
    }
}

void whileSchleife() {
    while (run) {
        radian = ((double) counter / 180) * PI;
        printf("Winkel: %3d Grad => Sinus-Funktionswert: %6.3f \n", counter, sin(radian));
        counter += 10;
        if (counter > 360) {
            run = 0;
        }
    }
}
