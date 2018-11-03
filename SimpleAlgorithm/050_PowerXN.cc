#include <iostream>

using namespace std;
/*
    0 ms 100.0%
    LC 50 power(x, n) x is double from -100 to 100
    n is integer from INT32_MIN to INT32_MAX

    学习：
    1. 【界定】边界条件，通过所有的test cases !!!
    2. 防止【overflow】，需要其他类型的【int -> long】，学习如何自主【选择】 test cases

    算法：简单
    1. 算法就是改编自power(x,n)，复杂度是 O(logN)

    重点：
    1. 先判断 n 是否超出边界，是则直接return；当n为负数时，做出相应的变化 -> 变成正数的情况
*/

static const auto speedup =[]() {std::ios::sync_with_stdio(false); std::cin.tie(NULL); return 0;}();
class Solution {
public:
    double myPow(double x, int n) {
        long n_long = n;
        if(n_long > INT32_MAX || n_long < INT32_MIN)
            return 1;
        if(n_long < 0){
            x = 1/ x;
            n_long = - n_long;
        }
        double prod = 1;
        while( n_long > 0){
            if(n_long % 2 ==1 )
                prod *= x;
            n_long /= 2;
            x *= x;
        }
        return prod;
    }
};

int main(){
    Solution a;
    cout << a.myPow(2.00, 10) << '\n';
    cout << a.myPow(0.0001, INT32_MAX) << '\n';
    cout << a.myPow(2.00, INT32_MIN) << '\n';
}