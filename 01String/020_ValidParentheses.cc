#include <iostream>
#include <cstring>
using namespace std;

/*
  学习：
  1. 堆栈的简单思路
  2. 如何使用str中的各类方法？ Onenote\\C++\\string str.push_back(x), str.pop_back(), str.empty()?, str.back()

  算法：简单
  1. 搞清楚，这就是个简单的堆栈，如果是前，则入栈；不是(后)，则判断是否相等并出栈，当最后栈为空时则为 true

  重点：

*/

static const auto speedup =[]() {std::ios::sync_with_stdio(false); std::cin.tie(NULL); return 0;}();
class Solution {
public:
    bool isValid(string s) {
        if(s.empty()) return true;
    string stack; int len = s.length();
    for(int i = 0; i < len; i++){
        if(s[i] == '(' || s[i] == '{' || s[i] == '['){
            switch(s[i]){
                case '(': {stack.push_back(')'); break;}
                case '{': {stack.push_back('}'); break;}
                case '[': {stack.push_back(']'); break;}
            }
        }
        else{
            if(!stack.empty() && s[i] == stack.back()){
                stack.pop_back();
            }
            else
                return false;
        }
    }
    return (stack.empty())? true: false;
    }
};

int main(){
    Solution sol;
    cout << sol.isValid("") << endl;
    cout << sol.isValid("()") << endl;
    cout << sol.isValid("()[]{}") << endl;
    cout << sol.isValid("(([]){})") << endl;
}