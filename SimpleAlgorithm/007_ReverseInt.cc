#include <iostream>
using namespace std;

/*
  学习：
  1. 如何理解 overflow 和 题目中的条件，如何防止result不受到数据类型的影响？ Onenote\\C++\\Overflow
  2. dealing with an environment which could only store integers within the 32-bit signed integer range INT32_MIN, INT32_MAX
     这里的意思明显是说运算过程中的【中间结果 超过范围】则return 0
  3. 负数的 % 和 / 运算

  算法：
  1. 重点：无需判断正负，算法都可以完成整数的反转：理解负数的运算！
*/

static const auto speedup =[]() {std::ios::sync_with_stdio(false); std::cin.tie(NULL); return 0;}();
class Solution {
public:
    int reverse(int x) {
        long long x_long = x;
        long long ans = 0;
        while(x_long != 0){
            ans =  ans * 10 + x_long % 10;
            if(ans > INT32_MAX || ans < INT32_MIN)
                return 0;
            x_long = x_long /10;
        }
        return ans;
    }
};

int main(){
    Solution a;
    cout << "INT32_MAX: " << INT32_MAX << endl;
    cout << "INT32_MIN: " << INT32_MIN << endl;
    cout << a.reverse(145633) << '\n';
    cout << a.reverse(-145633) << '\n';
    cout << long(a.reverse(INT32_MAX)) << '\n';
    cout << long(a.reverse(INT32_MIN)) << '\n';
    cout << long(a.reverse(INT32_MAX - 7)) << '\n';
    cout << long(a.reverse(INT32_MIN + 8)) << '\n';
}