#include <iostream>
#include <string>
#include <sstream>
#include <cmath>
#include <vector>

using namespace std;

typedef long long lint;

lint strToInt(const string & string_temp) {
  lint int_temp = 0;
  stringstream stream(string_temp);
  stream >> int_temp;
  return int_temp;
}

int numberDigits(lint number) {
  int digit = 0;
  while (number != 0) {
    digit = digit + 1;
    number = (lint)(number / 10);
  }
  return digit;
}

lint reverseN(lint n, int digit) {
  lint result = 0;
  for (int i = 0; i < digit; i++) {
    result = result + pow(10, digit - i - 1) * (n % 10);
    n = (lint)(n / 10);
  }
  return result; 
}

int PalindromeNumber(int digit) {
  if (digit == 1) {
    return 10;
  }
  return 9 * pow(10, (int)((digit - 1) / 2));
}

lint getPalindromeBase(int digit, int index) {
  int creatN = digit / 2;
  if (digit % 2 == 0) {
    return index + pow(10, creatN - 1) - 1;
  } else {
    if (index % 10 == 0) {
      return ((lint)(index / 10)) + pow(10, creatN - 1);
    } else {
      return ((lint)(index / 10)) + pow(10, creatN - 1) + 1;
    }
    if (digit == 1) {
      return 0;
    }
  }
}

lint getPalindrome(int digit, int index) {
  lint result = 0;
  int base = 0;
  int creatN = digit / 2;
  if (digit % 2 == 0) {
    base = index + pow(10, creatN - 1) - 1;
    lint rn = reverseN(base, creatN);
    result = (lint)(base * pow(10, creatN)) + rn;
  } else {
    base = ((int)(index / 10)) + pow(10, creatN - 1);
    if (index % 10 == 0) {
      base = base - 1;
    }
    /*
    if (index % 10 == 0) {
      base = ((int)(index / 10)) + pow(10, creatN - 1);
    } else {
      base = ((int)(index / 10)) + pow(10, creatN - 1) + 1;
    }*/
    if (digit == 1) {
      base = 0;
    }
    int j = ((index % 10) - 1);
    if (j == -1) {
      j = 9;
    }
    if (digit == 1) {
      j = index - 1;
    }
    result = (lint)(base * pow(10, creatN + 1)) + (lint)(j * pow(10, creatN)) + reverseN(base, creatN);
  }
  return result;
}

int PalindromeIndex(int digit, lint n) {
  int base = 0;
  int creatN = digit / 2;
  for (int i = 0; i < creatN; i++) {
    base = base + pow(10, creatN - i - 1) * (n % 10);
    n = n / 10;
  }
  if (digit % 2 == 0) {
    return base - pow(10, creatN - 1) + 1; 
  } else {
    int j = n % 10;
    if (digit == 1) {
      j = n - 1;
    }
    return (base - pow(10, creatN - 1)) * 10 + j + 1;
  }
}

lint firstDigit(int digit) {
  return pow(10, digit - 1) + 1;
}

lint endDigit(int digit) {
  lint result = 0;
  for (int i = 0; i < digit; i++) {
    result = result + 9 * pow(10, i);
  }
  return result;
}

bool isPalindrome(lint n) {
  lint rn = reverseN(n, numberDigits(n));
  return rn == n;
}

vector<lint> findPalindrom(lint now);

string nearestPalindromic(string n);

int main(int argc, char *argv[])
{
  while (true) {
    char number[100];
    std::cout << "Please input Number:";
    std::cin >> number;
    if (strToInt(number) == 0) {
      break;
    }
    printf("SrSS:%lld\n", reverseN(807045053, 9));
    /*
    printf("---------result0:%d\n", primePalindrome(strToInt(number))); 
    printf("---------result1:%d\n", primePalindrome(strToInt(number), 1)); 
    */
    //printf("PalindromeNumberI:%s\n", nearestPalindromic("807045053224792883").c_str()); 
    //printf("PalindromeNumber:%s\n", nearestPalindromic(number).c_str()); 
    //printf("Index:%d\n", PalindromeIndex(numberDigits(strToInt(number)), strToInt(number))); 
    lint x = 807045053350540708;
    printf("getPalindrome:%lld, getPalindromeBase:%d\n", getPalindrome(18, 707045054), PalindromeIndex(18, x));
    /*
    char index[10000];
    std::cout << "Please input index:";
    std::cin >> index;
    printf("getPalindrome:%lld, getPalindromeBase:%lld\n", getPalindrome(strToInt(number), strToInt(index)), getPalindromeBase(strToInt(number), strToInt(index)));
    */
  }

  return 0;
}

vector<lint> findPalindrom(lint now) {
  //printf("Now:%d\n", now);
  vector<lint> results; 
  int digit = numberDigits(now);
  if (isPalindrome(now)) {
    if (now == firstDigit(digit)) {
      results.push_back(endDigit(digit - 1));
      results.push_back(getPalindrome(digit, 2));
    } else if (now == endDigit(digit)) {
      printf("PD:%d\n", PalindromeNumber(digit));
      results.push_back(getPalindrome(digit, PalindromeNumber(digit) - 1));
      results.push_back(firstDigit(digit + 1));
    } else {
      int index = PalindromeIndex(digit, now);
      results.push_back(getPalindrome(digit, index - 1));
      results.push_back(getPalindrome(digit, index + 1));
    }
    return results;
  }

  lint firstPalfff = firstDigit(digit);
  lint lastEndPalfff = endDigit(digit - 1);
  if (now > lastEndPalfff && now < firstPalfff) {
    results.push_back(lastEndPalfff);
    results.push_back(firstPalfff);
    return results;
  }
  //lint digitEnd = endDigit(digit); 
  //printf("digitEnd:%d\n", digitEnd);
  int creatN = digit / 2;
  lint result = 0;
  int firstI = 1;
  int endI = PalindromeNumber(digit);
  while (true) {
    double middleI = ((double)firstI + (double)endI) / 2;
    if ((int)(middleI) != middleI && (abs(endI - firstI) == 1)) {
      results.push_back(getPalindrome(digit, firstI));
      results.push_back(getPalindrome(digit, endI));
      return results;
    }
    lint middlePal = getPalindrome(digit, middleI); 
    //printf("firstPal:%d\n", getPalindrome(digit, firstI));
    //printf("MiddlePal:%d\n", middlePal);
    //printf("endPal:%d\n", getPalindrome(digit, endI));
    if (now > middlePal) {
      firstI = middleI;  
    } else if (now < middlePal) {
      endI = middleI;
    } else {
      //return getPalindrome(digit, middleI - 1);
    }
  }
  printf("Lresult:%lld\n", result);
  //return findPalindrom(result + 1);
}

string nearestPalindromic(string n) {
  lint nN = strToInt(n);
  vector<lint> result = findPalindrom(nN);
  int f0 = abs(result[0] - nN);
  int f1 = abs(result[1] - nN);
  if (f0 < f1) {
    return to_string(result[0]);
  } else if (f0 > f1){
    return to_string(result[1]);
  } else {
    return to_string(result[0]);
  }
}

