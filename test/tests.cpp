// Copyright 2025 UNN-CS

#include <gtest/gtest.h>
#include <cstdint>
#include "alg.h"


TEST(st1, checkPrime_zero_and_one) {
    EXPECT_FALSE(checkPrime(0));
    EXPECT_FALSE(checkPrime(1));
}

TEST(st1, checkPrime_small_primes) {
    EXPECT_TRUE(checkPrime(2));
    EXPECT_TRUE(checkPrime(3));
    EXPECT_TRUE(checkPrime(5));
}

TEST(st1, checkPrime_small_composites) {
    EXPECT_FALSE(checkPrime(4));
    EXPECT_FALSE(checkPrime(6));
    EXPECT_FALSE(checkPrime(9));
}

TEST(st1, checkPrime_large_values) {
    EXPECT_TRUE(checkPrime(97));
    EXPECT_FALSE(checkPrime(100));
}

TEST(st1, checkPrime_square_of_large_prime_is_composite) {
    EXPECT_FALSE(checkPrime(121));
    EXPECT_FALSE(checkPrime(169));
}

TEST(st1, checkPrime_even_large_number_is_composite) {
    EXPECT_FALSE(checkPrime(1000000));
}

TEST(st1, nPrime_zero_returns_zero) {
    EXPECT_EQ(0, nPrime(0));
}

TEST(st1, nPrime_first) {
    EXPECT_EQ(2, nPrime(1));
}

TEST(st1, nPrime_second) {
    EXPECT_EQ(3, nPrime(2));
}

TEST(st1, nPrime_third) {
    EXPECT_EQ(5, nPrime(3));
}

TEST(st1, nPrime_tenth) {
    EXPECT_EQ(29, nPrime(10));
}

TEST(st1, nPrime_twenty_fifth) {
    EXPECT_EQ(97, nPrime(25));
}

TEST(st1, nextPrime_from_zero_and_one) {
    EXPECT_EQ(2, nextPrime(0));
    EXPECT_EQ(2, nextPrime(1));
}

TEST(st1, nextPrime_from_composite) {
    EXPECT_EQ(5, nextPrime(4));
}

TEST(st1, nextPrime_from_prime) {
    EXPECT_EQ(13, nextPrime(11));
}

TEST(st1, nextPrime_large_gap) {
    EXPECT_EQ(101, nextPrime(100));
}

TEST(st1, sumPrime_less_than_2) {
    EXPECT_EQ(0, sumPrime(0));
    EXPECT_EQ(0, sumPrime(1));
    EXPECT_EQ(0, sumPrime(2));
}

TEST(st1, sumPrime_boundary_after_first_prime) {
    EXPECT_EQ(2, sumPrime(3));
}

TEST(st1, sumPrime_small) {
    EXPECT_EQ(17, sumPrime(10));
}

TEST(st1, sumPrime_medium) {
    EXPECT_EQ(77, sumPrime(20));
}

TEST(st1, sumPrime_100) {
    EXPECT_EQ(1060, sumPrime(100));
}
