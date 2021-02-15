#include <iostream>
#include <map>
#include <string>
#include <vector>

using namespace std;

class Solution {
  public:
    map<int, string> romanMap{{1000, "M"}, {900, "CM"}, {500, "D"}, {400, "CD"},
                              {100, "C"},  {90, "XC"},  {50, "L"},  {40, "XL"},
                              {10, "X"},   {9, "IX"},   {5, "V"},   {4, "IV"},
                              {1, "I"}};

    int    numLeft;
    string result;

    void numProc(int modNum)
    {
        int loopNum = numLeft / modNum;
        for (int i = 0; i < loopNum; i++) {
            result  = result + romanMap.at(modNum);
            numLeft = numLeft - modNum;
        }
    }

    string intToRoman(int num)
    {
        numLeft = num;
        if (numLeft >= 1000) {
            numProc(1000);
        }
        if (numLeft < 1000 && numLeft >= 900) {
            numProc(900);
        }
        if (numLeft < 900 && numLeft >= 500) {
            numProc(500);
        }
        if (numLeft < 500 && numLeft >= 400) {
            numProc(400);
        }
        if (numLeft < 400 && numLeft >= 100) {
            numProc(100);
        }
        if (numLeft < 100 && numLeft >= 90) {
            numProc(90);
        }
        if (numLeft < 90 && numLeft >= 50) {
            numProc(50);
        }
        if (numLeft < 50 && numLeft >= 40) {
            numProc(40);
        }
        if (numLeft < 40 && numLeft >= 10) {
            numProc(10);
        }
        if (numLeft < 10 && numLeft >= 9) {
            numProc(9);
        }
        if (numLeft < 10 && numLeft >= 5) {
            numProc(5);
        }
        if (numLeft < 5 && numLeft >= 4) {
            numProc(4);
        }
        if (numLeft < 4 && numLeft >= 0) {
            numProc(1);
        }

        return result;
    }
};

int main()
{
    Solution slt;
    printf(slt.intToRoman(2352).c_str());
    return 0;
}
