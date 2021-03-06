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
int numberPO = 0;
int numberPJ = 0;

int strToInt(const std::string & string_temp) {
  int int_temp = 0;
  std::stringstream stream(string_temp);
  stream >> int_temp;
  return int_temp;
}

int numberDigits(int number);

int endDigit(int digit);

int reverseN(int n, int digit);

int createPalindromS(int base, bool isO, int i = 0) {
  std::string z = std::to_string(base);  
  std::string rz = z;
  reverse(rz.begin(), rz.end());
  if (isO) {
    return strToInt(z + rz);
  } else {
    std::string jz = std::to_string(i);
    return strToInt(z + jz + rz);
  }
}

bool isPrime(int n);
int findNextPalindromP(int now);

int PalindromeNumber(int digit);

int getPalindromeBase(int digit, int index);

int getPalindrome(int digit, int index);

int findPalindrom(int now);

int testPalindromPrime(int now);

std::vector<int> createPalindroms(int start, int digit);

bool isPalindrome(int n);

int primePalindrome(int N, int s = 0);

int main(int argc, char *argv[])
{
  printf("ND:%d\n", numberDigits(1111)); 
  printf("ED:%d\n", endDigit(4)); 
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
    /*
    printf("---------result0:%d\n", primePalindrome(strToInt(number))); 
    printf("---------result1:%d\n", primePalindrome(strToInt(number), 1)); 
    */
    printf("PalindromeNumber:%d\n", PalindromeNumber(strToInt(number))); 
    char index[10000];
    std::cout << "Please input index:";
    std::cin >> index;
    printf("getPalindrome:%d, getPalindromeBase:%d\n", getPalindrome(strToInt(number), strToInt(index)), getPalindromeBase(strToInt(number), strToInt(index)));
  }
  clock_t startT1, endT1;
  clock_t startT2, endT2;
  clock_t stackT3, endT3;
  clock_t stackT4, endT4;

  startT1 = clock();
  int ppe = primePalindrome(9989900); 
  endT1 = clock();
  //100111001
  startT2 = clock();
  /*
  bool isP = isPrime(9999999);
  int i = 0;
  if (isP) {
    i = 1;
  }
  */
  int i = primePalindrome(9989900, 1);
  endT2 = clock();
  int test_j_n = 4;
  std::vector<int> test_j = createPalindroms(pow(10, test_j_n), test_j_n);
  printf("NumberO:%d\n", numberPO);
  printf("NumberJ:%d\n", numberPJ);
  printf("OThe Number is %d\n", number_ou);
  printf("JThe Number is %d\n", number_ju);

  printf("result:%d, time:%fs\n", ppe, (double)(endT1 - startT1) / CLOCKS_PER_SEC);
  //printf("result:%d, time:%fs\n", i, (double)(endT2 - startT2) / CLOCKS_PER_SEC);
  printf("result:%d, time:%fs\n", i, (double)(endT2 - startT2) / CLOCKS_PER_SEC);

  stackT3 = clock();
  //int reN = createPalindrom(1234, 4, false, 0);
  endT3 = clock();
  stackT4 = clock();
  int reS = createPalindromS(1234, false, 0);
  endT4 = clock();


  //printf("re:%d, time:%fs\n", reN, (double)(endT3 - stackT3) / CLOCKS_PER_SEC); 
  printf("re:%d, time:%fs\n", reS, (double)(endT4 - stackT4) / CLOCKS_PER_SEC); 
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

int endDigit(int digit) {
  int result = 0;
  for (int i = 0; i < digit; i++) {
    result = result + 9 * pow(10, i);
  }
  return result;
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

int reverseN(int n, int digit) {
  int result = 0;
  for (int i = 0; i < digit; i++) {
    result = result + pow(10, digit - i - 1) * (n % 10);
    n = (int)(n / 10);
  }
  return result; 
}

int findNextPalindromP(int now) {
  printf("Now:%d\n", now);
  int digit = numberDigits(now);
  int digitEnd = endDigit(digit); 
  if (digit % 2 == 0) {
    return findNextPalindromP(pow(10, digit));
  }
  printf("digitEnd:%d\n", digitEnd);
  if (now == digitEnd) {
    printf("HHH\n");
    return findNextPalindromP(now + 1);
  }
  int creatN = digit / 2;
  int result = 0;
  int last = pow(10, creatN - 1);
  int endNum = endDigit(creatN);
  printf("last:%d\n", last);
  printf("endNum:%d\n", endNum);
  for (int i = last; i <= endNum; i++) {
    if ((i % 2 == 0 && digit == 3)) {
      continue;
    }
    int re = reverseN(i, creatN);
    if (digit % 2 == 0) {
      result = i * pow(10, creatN) + re;
      if (now < result) {
        //printf("FindNextO:%d\n", result);
        if (isPrime(result)) {
          //printf("FindNextOF:%d\n", result);
          return result;
        }
      }
    } else {
      for (int j = 0; j <= 9; j++) {
        result = i * pow(10, creatN + 1) + j * pow(10, creatN) + re;
        if (now < result) {
          printf("now:%d,FindNextJ:%d\n", now, result);
          if (isPrime(result)) {
            //printf("FindNextJF:%d\n", result);
            return result;
          }
        }
      }
    }
  }
  printf("Lresult:%d\n", result);
  return findNextPalindromP(result + 1);
}

int PalindromeNumber(int digit) {
  return 9 * pow(10, (int)((digit - 1) / 2));
}

int getPalindromeBase(int digit, int index) {
  int creatN = digit / 2;
  if (digit % 2 == 0) {
    return index + pow(10, creatN - 1) - 1;
  } else {
    if (index % 10 == 0) {
      return ((int)(index / 10));
    } else {
      return ((int)(index / 10)) + 1;
    }
  }
}

int getPalindrome(int digit, int index) {
  int result = 0;
  int base = 0;
  int creatN = digit / 2;
  if (digit % 2 == 0) {
    base = index + pow(10, creatN - 1) - 1;
    //printf("base:%d\n", base);
    result = base * pow(10, creatN) + reverseN(base, creatN);
  } else {
    if (index % 10 == 0) {
      base = ((int)(index / 10));
    } else {
      base = ((int)(index / 10)) + 1;
    }
    printf("base:%d\n", base);
    int j = ((index % 10) - 1);
    if (j == -1) {
      j = 9;
    }
    result = base * pow(10, creatN + 1) + j * pow(10, creatN) + reverseN(base, creatN);
  }
  return result;
}

int findPalindrom(int now) {
  //printf("Now:%d\n", now);
  int digit = numberDigits(now);
  int digitEnd = endDigit(digit); 
  if (digit % 2 == 0) {
    return findNextPalindromP(pow(10, digit));
  }
  //printf("digitEnd:%d\n", digitEnd);
  if (now == digitEnd) {
    printf("HHH\n");
    return findNextPalindromP(now + 1);
  }
  int creatN = digit / 2;
  int result = 0;
  int firstI = 1;
  int endI = PalindromeNumber(digit);
  int firstN = pow(10, digit - 1);
  int endB = endDigit(creatN);
  while (true) {
    double middleI = ((double)firstI + (double)endI) / 2;
    if ((int)(middleI) != middleI && (abs(endI - firstI) == 1)) {
      result = getPalindrome(digit, endI);
      printf("firstI:%d, firstPal:%d\n", firstI, getPalindrome(digit, firstI));
      printf("middleI:%f, middlePal:%d\n", middleI, getPalindrome(digit, middleI));
      printf("endI:%d, Base:%d, endPal:%d\n", endI, getPalindromeBase(digit, endI), getPalindrome(digit, endI));
      return endI;
    }
    int middlePal = getPalindrome(digit, middleI); 
    //printf("firstPal:%d\n", getPalindrome(digit, firstI));
    //printf("MiddlePal:%d\n", middlePal);
    //printf("endPal:%d\n", getPalindrome(digit, endI));
    if (now > middlePal) {
      firstI = middleI;  
    } else if (now < middlePal) {
      endI = middleI;
    } else {
      return middleI;
    }
  }
  printf("Lresult:%d\n", result);
  return findPalindrom(result + 1);
}

int testPalindromPrime(int now) {
  printf("Now:%d\n", now);
  int digit = numberDigits(now);
  int digitEnd = endDigit(digit); 
  if (digit % 2 == 0) {
    return findNextPalindromP(pow(10, digit));
  }
  printf("digitEnd:%d\n", digitEnd);
  if (now == digitEnd) {
    printf("HHH\n");
    return findNextPalindromP(now + 1);
  }
  int creatN = digit / 2;
  int result = 0;
  int last = getPalindromeBase(digit, findPalindrom(now));
  printf("TPP:%d\n", last);
  int endNum = endDigit(creatN);
  printf("last:%d\n", last);
  printf("endNum:%d\n", endNum);
  for (int i = last; i <= endNum; i++) {
    if ((i % 2 == 0 && digit == 3)) {
      continue;
    }
    int re = reverseN(i, creatN);
    if (digit % 2 == 0) {
      result = i * pow(10, creatN) + re;
      if (now < result) {
        //printf("FindNextO:%d\n", result);
        if (isPrime(result)) {
          //printf("FindNextOF:%d\n", result);
          return result;
        }
      }
    } else {
      for (int j = 0; j <= 9; j++) {
        result = i * pow(10, creatN + 1) + j * pow(10, creatN) + re;
        if (now < result) {
          printf("now:%d,FindNextJ:%d\n", now, result);
          if (isPrime(result)) {
            //printf("FindNextJF:%d\n", result);
            return result;
          }
        }
      }
    }
  }
  printf("Lresult:%d\n", result);
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
      numberPO = numberPO + 1;
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
      for (int j = 0; j <= 9; j++) {
        numberPJ = numberPJ + 1;
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

int primePalindrome(int N, int s) {
  //1 find the Palindrome number; then in Palindrome number list find the prime.
  int temp = N;
  for (int i = temp; i <= 7; i++) {
    if (isPrime(i)) {
      return i;
    }
  }
  if (temp <= 11) {
    return 11;
  }
  if (isPalindrome(temp) && isPrime(temp)) {
    return temp;
  }
  //printf("Last:%d", temp);
  if (s == 0) {
    return findNextPalindromP(temp);
  } else if (s == 1) {
   return testPalindromPrime(temp); 
  }
}
