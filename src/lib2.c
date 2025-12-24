#include "contracts.h"

int GCF(int A, int B) {
    int min = (A < B) ? A : B;
    for (int i = min; i > 0; i--) {
        if (A % i == 0 && B % i == 0) {
            return i;
        }
    }
    return 1; 
}

float E(int x) {
    float sum = 1.0f;
    float term = 1.0f;
    
    for (int n = 1; n <= x; n++) {
        term /= n;
        sum += term;
    }
    return sum;
}
