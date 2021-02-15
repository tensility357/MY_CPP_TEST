#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;
class Solution {
  public:
    int arrayPairSum(vector<int>& nums)
    {
        if (nums.size() == 0) {
            return 0;
        }
        std::sort(nums.begin(), nums.end());
        int sum = 0;
        for (int i = 0; i < nums.size(); i = i + 2) {
            //sum += min(nums[i], nums[i + 1]);
            sum += nums[i];
        }
        return sum;
    }
};

int main()
{
    vector<int> testcase = {6, 2, 6, 5, 1, 2};
    Solution    slt;
    int         res = slt.arrayPairSum(testcase);

    return 0;
}
