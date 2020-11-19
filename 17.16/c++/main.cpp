#include <iostream>
#include <vector>

using namespace std;

int helper(vector<int>& nums, int start ,int end) {
    if (start > end) {
        return 0;
    }
    int pick = nums[start] + helper(nums, start + 2, end);
    int unpick = helper(nums, start + 2, end);
    return max(pick, unpick);
}

int massage(vector<int>& nums) {
    return helper(nums, 0, nums.size() - 1);
}

int main(int argc, char *argv[])
{
    vector<int> nums;
    nums.push_back(1);
    nums.push_back(2);
    nums.push_back(3);
    nums.push_back(1);
    printf("Result:%d\n", massage(nums));
    return 0;
}

