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

int endDigit(int digit);

int findNextPalindrom(int now);

std::vector<int> createPalindroms(int start, int digit);

std::vector<int> findPalindrome(int start);

int primePalindrome(int N);

int main(int argc, char *argv[])
{
  std::vector<int> temp  = findPalindrome(22);
  for (int i = 0; i < temp.size(); i++) {
    printf("Index:%d\n", temp[i]);
  }
  printf("result:%d\n", findNextPalindrom(8)); 
  printf("re:%d\n", numberDigits(10)); 
  return 0;
}

int numberDigits(int number) {
  std::string str = std::to_string(number);
  return str.size();
}

int endDigit(int digit) {
  std::string end = "";
  for (int i = 0; i < digit; i++) {
    end.append("9");
  }
  return strToInt(end);
}

int findNextPalindrom(int now) {
  int digit = numberDigits(now);
  int digitEnd = endDigit(digit); 
  if (digit == 1) {
    if (now == 9) {
      return 11;
    } else {
      return now + 1;
    }
  }
  int creatN = digit / 2;
  int result = 0;
  int last = pow(10, creatN - 1);
  int endNum = endDigit(creatN);
  if (now == digitEnd) {
    return findNextPalindrom(now + 1);
  }
  for (int i = last; i <= endNum; i++) {
    if (digit % 2 == 0) {
      std::string z = std::to_string(i);
      std::string rz = z;
      reverse(rz.begin(), rz.end());
      result = strToInt(z + rz);
      if (now <= result) {
        return result;
      }
    } else {
      for (int j = 0; j <= 9; j++) {
        std::string z = std::to_string(i);
        std::string rz = z;
        reverse(rz.begin(), z.begin());
        std::string zj = std::to_string(j);
        result = strToInt(z + zj + rz);
        if (now <= result) {
          return result;
        }
      }
    }
  }
  return result;
}

std::vector<int> createPalindroms(int start, int digit) {
  std::vector<int> result;
  if (digit == 1) {
    for (int i = start; i < 10; i++) {
      result.push_back(i);
    }
    return result;
  }
  int creatN = digit / 2;
  for (int i = pow(10, creatN - 1); i <= endDigit(creatN); i++) {
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
  int reEnd = 0;
  for (int i = 0; i < result.size(); i++) {
    if (result[i] >= start) {
      reEnd =  i;
      break;
    }
  }
  result.erase(result.begin(), result.begin() + reEnd);
  return result;
}

std::vector<int> findPalindrome(int start) {
  int digit = numberDigits(start);
  for (int i = start; i <)
}


int primePalindrome(int N) {
  int result = N;
  //1 find the Palindrome number; then in Palindrome number list find the prime.

  

  return result;
}
