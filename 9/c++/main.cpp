#include <iostream>
#include <cmath>
#include <string>
#include <sstream>

int strToInt(const std::string & string_temp) {
  int int_temp = 0;
  std::stringstream stream(string_temp);
  stream >> int_temp;
  return int_temp;
}

int numberDigits(int number);
int reverseN(int n, int digit);

int isPalindrome(int x);

int main(int argc, char *argv[])
{
  char number[1000000];
  while (true) {
    std::cout << "Please input a Number:";
    std::cin >> number;
    long int n = strToInt(number);
    if (n == -1) {
      break;
    }
    if (isPalindrome(n)) {
      printf("result:%ld, True\n", n);
    } else {
      printf("result:%ld, False\n", n);
    }
  }
  return 0;
}

int numberDigits(int number) {
  int digit = 0;
  while (number != 0) {
    digit = digit + 1;
    number = (int)(number / 10);
  }
  return digit;
}

int reverseN(int n, int digit) {
  long int result = 0;
  for (int i = 0; i < digit; i++) {
    result = result + pow(10, digit - i - 1) * (n % 10);
    n = (int)(n / 10);
  }
  return result; 
}

int isPalindrome(int x) {
  if (x < 0) {
    return false;
  } else if (x >= 0 && x < 10) {
    return true;
  } else {
    int re = reverseN(x, numberDigits(x));
    return re == x;
  }
}
