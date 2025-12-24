#include <stdio.h>
#include "contracts.h"

int main() {
    int command;
    printf("Program 1 \n");
    printf("Usage: 1 <A> <B> | 2 <x>\n");

    while (scanf("%d", &command) != EOF) {
        if (command == 1) {
            int a, b;
            if (scanf("%d %d", &a, &b) == 2) {
                printf("GCF(%d, %d) = %d\n", a, b, GCF(a, b));
            }
        } else if (command == 2) {
            int x;
            if (scanf("%d", &x) == 1) {
                printf("E(%d) = %f\n", x, E(x));
            }
        } else {
            printf("Unknown command or switch not supported in static mode.\n");
        }
    }
    return 0;
}
