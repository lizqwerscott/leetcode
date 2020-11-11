#include <iostream>
#include <cmath>
#include <algorithm>

int numberDigit(int n) {
    int digit = 0;
    while (n != 0) {
        ++digit;
        n /= 10;
    }
    return digit;
}

int reverse1(int x) {
    long int result = 0;
    int digit = numberDigit(x);
    for (int i = 0; i < digit; i++) {
        result += (x % 10) * pow(10, digit - i - 1);
        x /= 10;
    }
    if (result >= pow(2, 31) - 1 || result <= -pow(2, 31)) {
        return 0;
    }
    return result;
}

int reverse2(int x) {
    long int result = 0;
    while (x != 0) {
        result = result * 10 + (x % 10);
        if (result >= pow(2, 31) - 1 || result <= -pow(2, 31)) {
            return 0;
        }
        x /= 10;
    }
    return result;
}

int main(int argc, char *argv[])
{
    printf("Result:%d\n", reverse1(1534236469));
    printf("Result:%d\n", reverse2(1534236469));
    return 0;
}

