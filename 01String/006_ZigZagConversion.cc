#include <iostream>
#include <map>
#include <vector>
#include <unordered_map>
using namespace std;

/*
  学习：
  1. 比较垃圾的题目

  算法：
  1. 重点：Exception为 当行数为1 的时候，直接返回 原字符串
  2. 逻辑：分 numRows 个字符串容器，代表每行的字符串，i从 0 到 numRows - 1，反复增加或减少后加入 
*/

static const auto speedup =[]() {std::ios::sync_with_stdio(false); std::cin.tie(NULL); return 0;}();
class Solution {
public:
    string convert(string s, int numRows) {
        string a[numRows];
        string ans;
        int len = s.length(); int i = 0, flag = 1, count = 0;
        int num = numRows - 1;
        if(!num) return s;
        while(count < len){
            a[i] += s[count];
            if(i % num == 0 && count != 0)
                flag = -flag;
            ++count;
            i += flag;
        }
        for(int j = 0; j < numRows; j++)
            ans += a[j];
        return ans;
    }
};

int main(){
    Solution sol;
    string s = "PAYPALISHIRING";
    cout << sol.convert(s, 3) << endl;
    cout << sol.convert(s, 4) << endl;
}