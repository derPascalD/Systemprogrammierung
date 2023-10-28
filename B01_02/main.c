#include <stdio.h>

void ausgabe1(void);
void ausgabe2(void);
void ausgabe3(void);

int main() {
    ausgabe1();
    printf("\n");
    ausgabe2();
    printf("\n");
    ausgabe3();
    return 0;
}

void ausgabe1() {
    int n;
    int run = 1;
    int counter;
    printf("Bitte eine Zahl eingeben.\n");
    scanf("%d", &n);

    do {
        if (counter < n) {
            printf("*");
        } else {
            run = 0;
            printf("\n");
        }
        counter++;
    } while (run);
}

void ausgabe2() {
    int n, i;
    printf("Bitte eine Zahl eingeben.\n");
    scanf("%d", &n);
    for (i = 0; i < n; i++) {
        int j;
        for (j = 0; j <= i; j++) {
            printf("*");
        }
        printf("\n");
    }
}

void ausgabe3() {
    int n, k = 0;
    printf("Bitte eine Zahl eingeben.\n");
    scanf("%d", &n);

    if (n % 2 == 0) n--;
    while (k <= n / 2 && n > 0) {
        int j;
        for (j = 0; j < (n / 2) - k; j++) {
            printf(" ");
        }
        for (j = 0; j <= k * 2; j++) {
            printf("*");
        }
        for (j = 0; j < (n / 2) - k; j++) {
            printf(" ");
        }
        k++;
        printf("\n");
    }
}
