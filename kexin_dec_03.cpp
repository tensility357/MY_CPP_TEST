// kexin_dec_03.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include "pch.h"
#include <iostream>
#include <map>
#include <set>
#include <vector>
using namespace std;
class Solution {
public:
    Solution() { }
    ~Solution() { }
    map<int, set<int>> allRules;
    vector<set<int>> results;
    set<int> currentCache;
    int SplitTasks(vector<int> tasks, vector<pair<int, int>> rules)
    {
        if (tasks.size() == 0) {
            return 0;
        }
        if (rules.size() == 0) {
            return 1;
        }
        for (auto& rule : rules) {
            if (allRules.count(rule.first) == 1) {
                allRules[rule.first].insert(rule.second);
            } else if (allRules.count(rule.first) == 0) {
                allRules[rule.first] = set<int> { rule.second };
            }
            if (allRules.count(rule.second) == 1) {
                allRules[rule.second].insert(rule.first);
            } else if (allRules.count(rule.second) == 0) {
                allRules[rule.second] = set<int> { rule.first };
            }
        }
        bool isFirstTask = true;
        for (auto& task : tasks) {
            // 如果当前task num是要处理的第一个task num，那么可以直接存入当前还可以放入task的currentCache中
            if (isFirstTask == true) {
                currentCache.insert(task);
                isFirstTask = false;
                continue;
            }
            // 当前处理的task num没有规则限制，那么可以直接放入当前激活容器currentCache
            if (allRules.count(task) == 0) {
                currentCache.insert(task);
                continue;
            }

            //当前处理的task num有规则限制，那么需要查看currentCache中有没有互斥元素，如果没有则插入currentCache；如果有，则需要将currentCache已有内容存入result作为一个切割好的子序列，然后清空后再存入当前的task num
            bool isMatchRule = false;
            for (auto rule : allRules[task]) {
                if (currentCache.count(rule) == 1) {
                    results.push_back(currentCache);
                    currentCache.clear();
                    currentCache.insert(task);
                    isMatchRule = true;
                    break;
                }
            }
            // 如果当前task num所具有的所有规则中的互斥元素在currentCache中都不存在，则当前task可以插入到currentCache中。
            if (isMatchRule == false) {
                currentCache.insert(task);
            }
        }
        //所有元素处理完后，将剩余的currentCache加入results作为最后一个序列。
        if (currentCache.size() != 0) {
            results.push_back(currentCache);
        }
        return results.size();
    }
};

int main()
{
    Solution slt;
    // testcase 1:
    vector<int> tasks = { 0, 2, 3, 5, 7, 8, 9, 10, 12 };
    vector<pair<int, int>> rules = { { 2, 5 }, { 2, 7 }, { 3, 8 }, { 5, 8 } };
    //testcase 2:
    // vector<int> tasks = { 0, 1, 2, 3, 4, 5 };
    // vector<pair<int, int>> rules = { { 0, 1 }, { 1, 2 }, { 2, 3 }, { 3, 4 }, { 4, 5 } };

    int splitNum = slt.SplitTasks(tasks, rules);
    std::cout << "能够切割出的最少序列数量为：" << splitNum << std::endl;
    system("pause");
    std::cout << "Hello World!\n";
}

// 运行程序: Ctrl + F5 或调试 >“开始执行(不调试)”菜单
// 调试程序: F5 或调试 >“开始调试”菜单

// 入门提示:
//   1. 使用解决方案资源管理器窗口添加/管理文件
//   2. 使用团队资源管理器窗口连接到源代码管理
//   3. 使用输出窗口查看生成输出和其他消息
//   4. 使用错误列表窗口查看错误
//   5. 转到“项目”>“添加新项”以创建新的代码文件，或转到“项目”>“添加现有项”以将现有代码文件添加到项目
//   6. 将来，若要再次打开此项目，请转到“文件”>“打开”>“项目”并选择 .sln 文件
