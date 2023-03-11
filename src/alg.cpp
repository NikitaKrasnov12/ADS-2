// Copyright 2022 NNTU-CS
#include <cstdint>
#include "alg.h"


double pown(double value, uint16_t n) {
  double count = 1;
    if (n == 0) {
        return 1;
    } else if (value==0){
        return 0;
    } else {
        while(true) {
            count *= value;
            n--;
            if (n == 0) {
                return count;
            }
        }
    }
}

uint64_t fact(uint16_t n) {
  uint16_t count = 1;
    while (true) {
        if (n == 0) {
            return 1;
        } else {
            count *= n;
            n--;
            if (n == 0) {
                return count;
            }
        }
    }
}

double calcItem(double x, uint16_t n) {
  double result = pown(x, n) / fact(n);
    return result;
}

double expn(double x, uint16_t count) {
  uint16_t i;
    double schet = 0;
    for (i = 0; i <= count; i++) {
        schet += calcItem(x,i);
    }
    return schet;
}

double sinn(double x, uint16_t count) {
  uint16_t k;
    double schet = 0;
    for (k = 1; k <= count; k++) {
        if (k == 2) {
            schet -= calcItem(x, 2 * k - 1);
        } else {
            schet += calcItem(x, 2 * k - 1);
        }
    }
    return schet;
}

double cosn(double x, uint16_t count) {
  uint16_t k;
    double schet = 0;
    for (k = 1; k <= count; k++) {
        if (k==2) {
            schet -= calcItem(x, 2 * k - 2);
        } else {
            schet += calcItem(x, 2 * k - 2);
        }
    }
    return schet;
}
