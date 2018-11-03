#include <iostream>
#include <map>
#include <vector>
#include <unordered_map>
using namespace std;

/*
  学习：Onenote\\C++\\Map
  1. 学习了C++中map,hashmap,unordered map的简单使用， include# <map><hashp_map><unordered_map>
  2. 使用map的简单遍历和查找，复杂度更低 O(1)
  3. 这里的 Map.count(...) > 0 也可以使用 Map.find(...) != Map.end(), 两者效果类似，后者应该会好一点
  4. Map.at(...) = Map[...] , at会做下标检查，没有则报错；后者没有返回空值

  算法：
  1. 【逻辑顺序】：在原有的map中先查找 remnant， 然后再插入新的值 
  2. brute force 很容易写，是一个两层嵌套循环，复杂度很高

  Q：
  1. C++ 的auto怎么用？ 如何标准地遍历一遍 map？
*/

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> Map;
        for(int i = 0; i < nums.size(); i++){
            if(Map.count(target - nums[i]) > 0)
                return vector<int>(2) = { Map[target - nums[i]] , i};
            Map[nums[i]] = i;
        }
        throw ("Not found exception");
    }
};

int main(){
    Solution sol;
    vector<int> nums = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int target = 12;
    vector<int> ans = sol.twoSum(nums, target);
    cout << ans[0] << ' ' << ans[1] << endl;
}