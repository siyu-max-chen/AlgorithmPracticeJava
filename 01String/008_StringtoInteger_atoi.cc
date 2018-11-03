#include <iostream>
using namespace std;

/*
  学习：
  1. string相关 Onenote\\C++\\String
  2. 如何使用 string 的 iterator

  算法：
  1. 逻辑：先循环一遍，当字符串指向都为' '时运行，直到第一个非空格字符；判断第一个是数字或+-？；循环计算ans，如果超出边界return
  2. 重点：先遍历所有空格，第一个非空格字符关键判断是三种中的哪种，剩下的很easy
*/

static const auto speedup =[]() {std::ios::sync_with_stdio(false); std::cin.tie(NULL); return 0;}();
class Solution {
public:
    int myAtoi(string str) {
        long long ans = 0;
        bool is_positive = true;
        string::const_iterator it = str.begin();
        while( *it == ' '){
            ++ it;
        }
        if(*it == '+')
            ++ it;
        else if(*it == '-'){
            is_positive = false;
            ++ it;
        }
        else if( 47 < *it && *it < 58){
            ans = *it - 48;
            ++ it;
        }
        else
            return 0;
        while(it != str.end()){
            if( 47 < *it && *it < 58){
                ans = ans * 10 + *it - 48;
                if(is_positive && ans > INT_MAX)
                    return INT_MAX;
                if(!is_positive && ans > INT_MIN - 1)
                    return INT_MIN;
                ++ it;
            }
            else
                return (is_positive)? ans: -ans;
        }
        return (is_positive)? ans: -ans;
    }
};

int main(){
    Solution a;
    cout << a.myAtoi("42") << endl;
    cout << a.myAtoi("   -42") << endl;
    cout << a.myAtoi("4193 with words") << endl;
    cout << a.myAtoi("words and 987") << endl;
}