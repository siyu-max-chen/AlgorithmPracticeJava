#include <iostream>
#include <cstring>
#include <vector>
#include <algorithm>
using namespace std;

/*
  学习：
  1. 如何使用<algorithm>里的 sort 或 qsort

  算法：简单
  1. 先排序，这样第一个成员的长度能保证是最短的，可以直接从 0到长度-1 遍历
  2. 遍历比较，一旦不同则返回，否则加入字符串中

  重点：
  一些问题可以先考虑排序！！！是否值得O(nlogn)的代价

*/

static const auto speedup =[]() {std::ios::sync_with_stdio(false); std::cin.tie(NULL); return 0;}();
class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        string ans = ""; int i = 0, j;
        if(strs.size() == 0)
            return ans;
        sort(strs.begin(), strs.end());
        while( i < strs[0].length()) {
            char check = strs[0][i];
            for (int j = 0; j < strs.size(); j++) {
                if (strs[j][i] != check)
                    return ans;
            }
            ans += strs[0][i];
            ++i;
        }
        return ans;
    }
};

int main(){
    Solution sol;
    vector<string> strs = {"flower", "flow", "flight"};
    cout << sol.longestCommonPrefix(strs) << endl;
}

