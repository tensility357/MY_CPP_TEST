#include <algorithm>
#include <iostream>
#include <set>
#include <string>
#include <vector>

using namespace std;
class Solution {
  public:
    int lengthOfLongestSubstring(string s)
    {
        // 空字符或者1个字符的情况需要过滤
        if (s.size() <= 1) {
            return s.size();
        }
        int       left   = 0;
        int       right  = 1;
        int       maxLen = 1;
        int       temp   = 1;
        set<char> currentSeq;
        while (right <= (s.size() - 1)) {
            if (currentSeq.size() == 0) {
                currentSeq.insert(s[left]);
            }
            if (currentSeq.count(s[right]) == true) {
                // 如果出现重复字符，则调整起点
                left++;
                right  = left + 1;
                maxLen = max(temp, maxLen);
                // 清除临时存储
                temp = 1;
                currentSeq.clear();
                continue;
            }
            currentSeq.insert(s[right]);
            right++;
            temp++;
        }
        // 如果s为“au”这种right到达末尾的情况，则maxLen无法更新，需要在此处判断
        return max(maxLen, temp);
    }
};

int main()
{
    string   testcase = "pwwkew";
    Solution slt;
    int      res = slt.lengthOfLongestSubstring(testcase);
    return 0;
}
