#include <iostream>
#include <sstream>
#include "stdio.h"
#include <string>
#include <vector>
#include <cmath>
#include <algorithm>
#include <ctime>


int number_ou = 0;
int number_ju = 0;

int strToInt(const std::string & string_temp) {
  int int_temp = 0;
  std::stringstream stream(string_temp);
  stream >> int_temp;
  return int_temp;
}

int numberDigits(int number);

int endDigit(int digit);

bool isPrime(int n);
int findNextPalindromP(int now);

std::vector<int> createPalindroms(int start, int digit);

bool isPalindrome(int n);

int primePalindrome(int N);

int main(int argc, char *argv[])
{
  if (isPrime(8)) {
    printf("Prime\n"); 
  } else {
    printf("No\n");
  }
  while (true) {
    char number[100];
    std::cout << "Please input Number:";
    std::cin >> number;
    if (strToInt(number) == 0) {
      break;
    }
    printf("result:%d\n", primePalindrome(strToInt(number))); 
  }
  clock_t startT1, endT1;
  clock_t startT2, endT2;
  startT1 = clock();
  int ppe = primePalindrome(9989900); 
  endT1 = clock();
  //100111001
  startT2 = clock();
  bool isP = isPrime(9999999);
  int i = 0;
  if (isP) {
    i = 1;
  }
  endT2 = clock();
  int test_j_n = 3;
  std::vector<int> test_j = createPalindroms(pow(10, test_j_n), test_j_n);
  printf("OThe Number is %d\n", number_ou);
  printf("JThe Number is %d\n", number_ju);

  printf("result:%d, time:%fs\n", ppe, (double)(endT1 - startT1) / CLOCKS_PER_SEC);
  printf("result:%d, time:%fs\n", i, (double)(endT2 - startT2) / CLOCKS_PER_SEC);
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

bool isPrime(int n) {
  if (n <= 3) {
    return n > 1;
  }

  if (n % 6 != 1 && n % 6 != 5) {
    return false;
  }
  int sqrtN = (int)sqrt(n);
  for (int i = 5; i < sqrtN; i += 6) {
    if (n % i ==0 || n % (i + 2) == 0) {
      return false;
    }
  }
  return true;
}

int findNextPalindromP(int now) {
  int digit = numberDigits(now);
  int digitEnd = endDigit(digit); 
  if (digit == 1) {
    if (now == 9) {
      return 11;
    } else {
      for (int i = now; i < 9; i++) {
        if (isPrime(i)) {
          return i;
        }
      }
      return findNextPalindromP(10);
    }
  } else {
    if (digit != 2 && digit % 2 == 0) {
      return findNextPalindromP(pow(10, digit));
    }
  }
  if (now == digitEnd) {
    printf("HHH\n");
    return findNextPalindromP(now + 1);
  }
  int creatN = digit / 2;
  int result = 0;
  int last = pow(10, creatN - 1);
  int endNum = endDigit(creatN);
  for (int i = last; i <= endNum; i++) {
    if (i % 2 == 0 && digit == 3) {
      continue;
    }
    if (digit % 2 == 0) {
      std::string z = std::to_string(i);
      std::string rz = z;
      reverse(rz.begin(), rz.end());
      result = strToInt(z + rz);
      if (now < result) {
        //printf("FindNextO:%d\n", result);
        if (isPrime(result)) {
          //printf("FindNextOF:%d\n", result);
          return result;
        }
      }
    } else {
      for (int j = 0; j <= 9; j++) {
        std::string z = std::to_string(i);
        std::string rz = z;
        reverse(rz.begin(), z.begin());
        std::string zj = std::to_string(j);
        result = strToInt(z + zj + rz);
        if (now < result) {
          //printf("FindNextJ:%d\n", result);
          if (isPrime(result)) {
            //printf("FindNextJF:%d\n", result);
            return result;
          }
        }
      }
    }
  }
  printf("digitEnd:%d\n", digitEnd);
  return findNextPalindromP(result + 1);
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
      int result_t = strToInt(z + rz);
      if (i % 2 == 0) {
        if (isPrime(result_t)) {
          number_ou = number_ou + 1;
        }
        printf("O:root is o;\n");
      } else {
        if (isPrime(result_t)) {
          number_ju = number_ju + 1;
        }
        printf("O:root is j;\n");
      }
      if (isPrime(result_t)) {
        printf("Number:%d, is\n", result_t);
      } else {
        printf("Number:%d, no\n", result_t);
      }
    } else {
      for (int j = 1; j <= 9; j++) {
        std::string z = std::to_string(i);
        std::string rz = z;
        reverse(rz.begin(), rz.end());
        std::string zj = std::to_string(j);
        result.push_back(strToInt(z + zj + rz));
        int result_t = strToInt(z + zj + rz);
        if (i % 2 == 0) {
          if (isPrime(result_t)) {
            number_ou = number_ou + 1;
          }
          printf("J:root is o;\n");
        } else {
          if (isPrime(result_t)) {
            number_ju = number_ju + 1;
          }
          printf("J:root is j;\n");
        }
        if (isPrime(result_t)) {
          printf("Number:%d, is\n", result_t);
        } else {
          printf("Number:%d, no\n", result_t);
        }
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


bool isPalindrome(int n) {
  std::string z = std::to_string(n);
  std::string rz = z;
  reverse(rz.begin(), rz.end());
  return rz == z;
}

int primePalindrome(int N) {
  int result = N;
  //1 find the Palindrome number; then in Palindrome number list find the prime.
  int i = N;
  if (isPalindrome(i) && isPrime(i)) {
    return i;
  } else {
    return findNextPalindromP(i);
  }
  while (true) {
    if (isPrime(i)) {
      result = i;
      break;
    }
    i = findNextPalindromP(i);
  }
  return result;
}
