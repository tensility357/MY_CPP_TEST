#include <iostream>
#include <vector>

using namespace std;
class Solution {
  public:
    int num;
    int findCircleNum(vector<vector<int>>& isConnected)
    {
        vector<vector<int>> visitInfo{200, {0}};
        // 不能以整行是否被遍历来做是否dfs条件，因为第一行没遍历完看到与第二行有联系就会跳转到第二行，
        // 而第二行没遍历完看到和第一行有联系又会跳回第一行，这样就无限循环了。行第一个元素是必须看的。
        // 所以此处visitinfo必须定义全200*200，不能只定义200个。
        // vector<int> visitInfo(200);
        if (isConnected.size() == 0) {
            return 0;
        }
        for (int row = 0; row < isConnected.size(); row++) {
            // 统计圈子数量必须在此处，因为dfs里会将一个圈子的省设置为已访问，所以此处只要是没访问的一定是一个圈子。
            if (visitInfo[row][0] == 0) {
                num++;
                dfs(isConnected, row, visitInfo);
            }
            /* code */
        }
        return num;
    }
    void dfs(vector<vector<int>>& isConnected, int i, vector<vector<int>>& visitInfo)
    {
        if (visitInfo[i][0] == 1) {
            return;
        }

        visitInfo[i][0] = 1;
        for (int col = 0; col < isConnected[i].size(); col++) {
            if (isConnected[i][col] == 1 && visitInfo[col][0] == 0) {
                dfs(isConnected, col, visitInfo);
            }
        }
        // 不能在此处统计圈子数量，因为每个省遍遍历自己圈子时一定会执行到此处。
        // num++;
    }
};

int main()
{
    vector<vector<int>> testcase = {{1, 0, 0}, {0, 1, 0}, {0, 0, 1}};
    Solution            slt;
    int                 res = slt.findCircleNum(testcase);
    return 0;
}
