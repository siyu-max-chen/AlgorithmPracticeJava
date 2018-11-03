#include <iostream>
using namespace std;

int x = [](){ std::ios_base::sync_with_stdio(false); std::cin.tie(nullptr); return 0; }();
class Solution {
public:
    bool IsPalindromic(string s){
        int i = 0, j = s.length()-1;
        while(j > i){
            if(s[i] == s[j]){
                ++i; --j;
            }
            else
                return false;
        }
        return true;
    }
    string longestPalindrome(string s) {
        string ans; int max = 0; int count = 0; int left = 0;
        int len = s.length();
        for(int i = 0; i < len && len - i> max; i++){
            count = 0;
            for(int j = i; j < len; j++){
                if(IsPalindromic(s.substr(i, j - i + 1))){
                    count = j - i + 1;
                    if(count > max){
                        max = count;
                        left = i;
                    }
                }
            }
        }
        return s.substr(left, max);
    }
};

int main(){
    Solution a;
    cout << a.longestPalindrome("abcabcbb") << '\n';
    cout << a.longestPalindrome("abba") << '\n';
}