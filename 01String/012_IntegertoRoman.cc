#include <iostream>
#include <cstring>
using namespace std;

/*
  学习：
  1. 

  算法：
  1. 显然，位数从 高->低 的顺序换算更简单；
  2. 每一【位】有两组组合，因此需要两个数组，index为位数[0-3]，数组值为对应的字符
  3. 当前位数从高到 0，通过 div 获得当前位数的值，再根据值来做相应的转换

  重点：
  由于输入是有限的【0-3999】，只需要[4]个空间的大小

  Q：
  1. C++ 的auto怎么用？ 如何标准地遍历一遍 map？
*/

static const auto speedup =[]() {std::ios::sync_with_stdio(false); std::cin.tie(NULL); return 0;}();
class Solution {
public:
    string intToRoman(int num) {
        string ans;
        string A[4], B[4];
        A[0] = 'I'; A[1] = 'X'; A[2] = 'C'; A[3] = 'M';
        B[0] = 'V'; B[1] = 'L'; B[2] = 'D';
        int digit = 3; int div = 1000; int i = 0;
        while(div != 0){
            i = num / div;
            num = num - div * i;
            div /= 10;
            if(i == 0)
                ;
            else if(i >= 5){
                if(i == 9){
                    ans +=  A[digit] + A[digit + 1];
                }
                else{
                    ans += B[digit];
                    for(int j = 0; j < i - 5; j++)
                        ans += A[digit];
                }
            }
            else{
                if(i == 4)
                    ans +=  A[digit] + B[digit];
                else{
                    for(int j = 0; j < i; j++)
                        ans += A[digit];
                }
            }
            -- digit;
        }
        return ans;
    }
};

int main(){
    Solution sol;
    cout << sol.intToRoman(3) << endl;
    cout << sol.intToRoman(4) << endl;
    cout << sol.intToRoman(9) << endl;
    cout << sol.intToRoman(58) << endl;
    cout << sol.intToRoman(1994) << endl;
}