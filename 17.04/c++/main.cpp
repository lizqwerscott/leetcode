#include <istream>
#include <vector>

using namespace std;

int missingNumber1(vector<int>& nums);
int missingNumber2(vector<int>& nums);
int missingNumber3(vector<int>& nums);

int main(int argc, char *argv[])
{
   vector<int> nums;
   nums.push_back(3);
   nums.push_back(0);
   nums.push_back(1);
   printf("Result:%d\n", missingNumber3(nums));
    return 0;
}

int missingNumber1(vector<int>& nums) {
    int num = nums.size() + 1;
    bool isN[num];
    for (int i = 0; i < num; ++i) {
        isN[i] = false;
    }
    for (int i = 0; i < nums.size(); ++i) {
        isN[nums[i]] = true;
    }
    int result = -1;
    for (int i = 0; i < num; ++i) {
        if (!isN[i]) {
            return i;
        }
    }
    return result;
}

int missingNumber2(vector<int>& nums) {
    int sum = 0;
    int num = nums.size();
    for (int i = 0; i < num; ++i) {
        sum += nums[i];
    }
    return ((num * (num + 1)) / 2) - sum;
}

int missingNumber3(vector<int>& nums) {
    int res = 0;
    for (int i = 0; i < nums.size(); ++i) {
        res ^= i;
        res ^= nums[i];
    }
    res ^= nums.size();
    return res;
}
