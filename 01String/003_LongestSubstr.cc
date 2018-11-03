#include <iostream>
using namespace std;

int x = [](){ std::ios_base::sync_with_stdio(false); std::cin.tie(nullptr); return 0; }();
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int Map[256] ={0};
        int count = 0; int max = 0; int pivot = 0;
        for(int i = 0; i < s.length(); i++){
            if(Map[s[i]] > 0){
                if(count > max)
                    max = count;
                if(pivot > Map[s[i]]){
                    count ++;
                }
                else{
                    pivot = Map[s[i]];  // 指向没有重复的第一个词
                    count = i - Map[s[i]] + 1;  // i - pivot +1
                }
            }
            else{
                count++;
            }
            Map[s[i]] = i + 1;
        }
        return (max > count)?max:count;
    }
};

int main(){
    Solution a;
    cout << a.lengthOfLongestSubstring("abcabcbb") << '\n';
    cout << a.lengthOfLongestSubstring("pwwkew") << '\n';
}