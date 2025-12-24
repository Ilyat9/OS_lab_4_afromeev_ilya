#include <math.h>
#include "contracts.h"

int GCF(int A, int B) {
    while (B != 0) {
        int temp = B;
        B = A % B;
        A = temp;
    }
    return A;
}

float E(int x) {
    if (x == 0) return 1.0f; // Базовый случай, хотя x -> бесконечность
    return (float)pow(1.0 + 1.0/(float)x, x);
}
