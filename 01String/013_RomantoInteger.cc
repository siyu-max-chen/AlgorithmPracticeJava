#include <iostream>
#include <cstring>
using namespace std;

/*
  学习：
  1. 

  算法：
  1. 显然，位数从 低->高 的顺序换算更简单；
  2. 可以用数组建立一个 '字母' <-> 数值 的关系，用来直接计算 该 位置 string的大小
  3. 遇到大的为正常，遇到小的则计算这两位造成的影响而且 i-- 两次来跳过位置

  重点：
  使用数组时，一定要时刻注意不要【超出数组下标的范围】！！！

  Q：
  1. C++ 的auto怎么用？ 如何标准地遍历一遍 map？
*/

static const auto speedup =[]() {std::ios::sync_with_stdio(false); std::cin.tie(NULL); return 0;}();
class Solution {
public:
    int romanToInt(string s) {
        static int a[256];
        int ans = 0; int len = s.length();
        a['I'] = 1; a['V'] = 5; a['X'] = 10; a['L'] = 50;
        a['C'] = 100; a['D'] = 500; a['M'] = 1000;
        for(int i = len - 1; i > 0; i--){
            if(a[s[i-1]] >= a[s[i]])
                ans += a[s[i]];
            else {
                ans = ans + a[s[i]] - a[s[i - 1]];
                if (i == 1) return ans;
                --i;
            }
        }
        ans += a[s[0]];
        return ans;
    }
};

int main(){
    Solution sol;
    cout << sol.romanToInt("III") << endl;
    cout << sol.romanToInt("IV") << endl;
    cout << sol.romanToInt("IX") << endl;
    cout << sol.romanToInt("LVIII") << endl;
    cout << sol.romanToInt("MCMXCIV") << endl;
}