#include <iostream>
#include <cmath>
#include <string>
#include <sstream>
#include <vector>
#include <algorithm>

using namespace std;

typedef long long lint;

lint strToInt(const string & string_temp) {
  lint int_temp = 0;
  stringstream stream(string_temp);
  stream >> int_temp;
  return int_temp;
}

int minN(int x1, int x2) {
    if (x1 >= x2) {
        return x1;
    } else {
        return x2;
    }
}

int nthMagicalNumber(int N, int A, int B);

int main(int argc, char *argv[])
{
    while (true) {
        char number[1000];
        char nA[100];
        char nB[100];
        cout << "Please input Number:";         
        cin >> number;
        if (strToInt(number) == 0) {
            break;
        }
        cout << "A:";
        cin >> nA;
        cout << "B:";
        cin >> nB;
        printf("Result:%d\n", nthMagicalNumber(strToInt(number), strToInt(nA), strToInt(nB)));
    }
    return 0;
}

int nthMagicalNumber(int N, int A, int B) {
    lint modN = pow(10, 9) + 7;
    if (A == B) {
        return (N * A) % modN;
    }
    vector<lint> results;
    for (int i = 1; results.size() <= N + 2; ++i) {
        lint rA = A * i;
        lint rB = B * i;
        bool isAddrA = true;
        bool isAddrB = true;
        for (int j = 0; j < results.size(); j++) {
            if (results[j] == rA) {
                isAddrA = false;
            }
            if (results[j] == rB) {
                isAddrB = false;
            }
        }
        if (isAddrA) {
            results.push_back(rA);
        }
        if (isAddrB) {
            results.push_back(rB);
        }
        sort(results.begin(), results.end());
    }
    return results[N - 1] % modN;
}

