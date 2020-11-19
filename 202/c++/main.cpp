#include <iostream>
#include <cmath>
#include <vector>
#include <algorithm>
#include <sstream>
#include <string>

int strToInt(const std::string & string_temp) {
  int int_temp = 0;
  std::stringstream stream(string_temp);
  stream >> int_temp;
  return int_temp;
}

int getNext(int n) {
  int result = 0;
  while (n != 0) {
    result += pow(n % 10, 2);
    n /= 10;
  }
  return result;
}


bool isHappy1(int n) {
  int temp = n;
  std::vector<int> results;
  while (true) {
    int result = getNext(temp);
    printf("N:%d\n", result);
    if (result == 1) {
      return true;
    }
    if (find(results.begin(), results.end(), result) != results.end()) {
      return false;
    }
    results.push_back(result);
    temp = result;
  }
}

bool isHappy2(int n) {
  int slow = n;
  int quick = getNext(getNext(slow));
  while (true) {
    slow = getNext(slow);
    quick = getNext(getNext(quick));
    printf("S:%d\n", slow);
    printf("Q:%d\n", quick);
    if (quick == 1) {
      return true;
    }
    if (quick == slow) {
      return false;
    }
  }
}

int main(int argc, char *argv[])
{
  while (true) {
    char number[100000];
    std::cout << "N:";
    std::cin >> number;
    int num = strToInt(number);
    /*
    if (isHappy1(num)) {
      printf("%d is1 Hello\n", num);
    }
    */
    if (isHappy2(num)) {
      printf("%d is2 Ok\n", num);
    }
  }
  if (isHappy1(19)) {
    printf("Helle\n");
  }
  return 0;
}
