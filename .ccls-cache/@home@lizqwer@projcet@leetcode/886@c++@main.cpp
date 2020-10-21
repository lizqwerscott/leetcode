#include <iostream>
#include <sstream>
#include "stdio.h"
#include <string>
#include <vector>
#include <cmath>
#include <algorithm>

int strToInt(const std::string & string_temp) {
  int int_temp = 0;
  std::stringstream stream(string_temp);
  stream >> int_temp;
  return int_temp;
}

int numberDigits(int number);

std::vector<int> createPalindroms(int digit);

std::vector<int> findPalindrome(int start);

int primePalindrome(int N);

int main(int argc, char *argv[])
{
  std::vector<int> temp  = findPalindrome(1);
  for (int i = 0; i < temp.size(); i++) {
    printf("Index:%d\n", temp[i]);
  }
  printf("result:%d\n", numberDigits(100)); 
  printf("re:%d\n", numberDigits(10)); 
  return 0;
}

int numberDigits(int number) {
  std::string str = std::to_string(number);
  return str.size();
}

std::vector<int> createPalindroms(int digit) {
  std::vector<int> result;
  if (digit == 1) {
    for (int i = 0; i < 10; i++) {
      result.push_back(i);
    }
    return result;
  }
  int creatN = digit / 2;
  std::string endstr = "";
  for (int i = 0; i < creatN; i++) {
    endstr.append("9");
  }
  for (int i = pow(10, creatN - 1); i <= strToInt(endstr); i++) {
    if (digit % 2 == 0) {
      std::string z = std::to_string(i);
      std::string rz = z;
      reverse(rz.begin(), rz.end());
      result.push_back(strToInt(z + rz));
    } else {
      for (int j = 1; j <= 9; j++) {
        std::string z = std::to_string(i);
        std::string rz = z;
        reverse(rz.begin(), z.begin());
        std::string zj = std::to_string(j);
        result.push_back(strToInt(z + zj + rz));
      }
    }
  }
  return result;
}

std::vector<int> findPalindrome(int start) {
  int digit = numberDigits(start);
  return createPalindroms(digit);
}


int primePalindrome(int N) {
  int result = N;
  //1 find the Palindrome number; then in Palindrome number list find the prime.

  

  return result;
}
