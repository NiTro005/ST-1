// Copyright 2025 UNN-CS
#include <cstdint>

#include "alg.h"

namespace {
constexpr uint64_t kFirstPrime = 2;
constexpr uint64_t kFirstOddCandidate = 3;

uint64_t firstOddNumberGreaterThan(uint64_t value) {
    uint64_t candidate = value + 1;
    if (candidate <= kFirstPrime) {
        return kFirstPrime;
    }
    return candidate % 2 == 0 ? candidate + 1 : candidate;
}
}  // namespace

bool checkPrime(uint64_t value) {
    if (value <= 1) {
        return false;
    }
    if (value == kFirstPrime) {
        return true;
    }
    if (value % 2 == 0) {
        return false;
    }

    for (uint64_t divisor = kFirstOddCandidate; divisor <= value / divisor;
         divisor += 2) {
        if (value % divisor == 0) {
            return false;
        }
    }
    return true;
}

uint64_t nPrime(uint64_t n) {
    if (n == 0) {
        return 0;
    }
    if (n == 1) {
        return kFirstPrime;
    }

    uint64_t found = 1;
    uint64_t candidate = 1;
    while (found < n) {
        candidate += 2;
        if (checkPrime(candidate)) {
            ++found;
        }
    }

    return candidate;
}

uint64_t nextPrime(uint64_t value) {
    uint64_t candidate = firstOddNumberGreaterThan(value);
    if (candidate == kFirstPrime) {
        return candidate;
    }

    while (!checkPrime(candidate)) {
        candidate += 2;
    }

    return candidate;
}

uint64_t sumPrime(uint64_t hbound) {
    if (hbound <= kFirstPrime) {
        return 0;
    }

    uint64_t sum = kFirstPrime;
    for (uint64_t candidate = kFirstOddCandidate; candidate < hbound;
         candidate += 2) {
        if (checkPrime(candidate)) {
            sum += candidate;
        }
    }

    return sum;
}
