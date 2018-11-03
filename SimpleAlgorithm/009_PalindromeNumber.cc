#include <iostream>
#include <sstream>
using namespace std;


int x = [](){ std::ios_base::sync_with_stdio(false); std::cin.tie(nullptr); return 0; }();
class Solution {
public:
    bool isPalindrome(int x) {
        stringstream s;
        s << x;
        string str = s.str();
        int left = 0, right = str.length() - 1;
        while (right > left){
            if(str[left] == str[right]){
                ++left, --right;
            }
            else
                return false;
        }
        return true;
    }
};

int main(){
    Solution a;
    cout << a.isPalindrome(121) << '\n';
    cout << a.isPalindrome(-121) << '\n';
    cout << a.isPalindrome(10) << '\n';
}