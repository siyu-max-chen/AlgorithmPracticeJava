#include <iostream>
#include <unordered_map>
#include <map>
#include <vector>
using namespace std;

class Solution {
    /* ms: 99.98% in two sum
     * 学习了c++中map和hashMap和unordered map的写法，最佳解法用到了map，map的lookup time 为O(logN)而unordered 为
     * O(N),注意的是在一次遍历完成时需要先判断原来的map是否有“目标余数”，没有则再插入map中(用unorderedmap结果为8 ms)
     * Map.at() = Map[]
     */
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        std::map<int, int> Map;
        for(int i = 0; i < nums.size(); i++){
            if(Map.count(target - nums[i]) > 0 && Map.at(target - nums[i]) != i )
                return vector<int>(2) = {Map.at(target - nums[i]) ,i};
            Map[nums[i]] = i;
        }
        throw ("Not found exception");
    }
};
class Solution1 {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        std::unordered_map<int, int> HashMap;
        vector<int> ans(2);
        for(int i = 0; i < nums.size(); i++)
            HashMap[nums[i]] = i;
        for(int i = 0; i < nums.size(); i++){
            if(HashMap.count(target - nums[i]) > 0 && HashMap.at(target - nums[i]) != i )
                return ans = {i, HashMap.at(target - nums[i])};
        }
        return ans;
    }
};
int main(){
    vector<int> nums = {3, 3};
    int target = 6;
    Solution a;
    nums = a.twoSum(nums,target);
    cout << nums[0] << ' ' << nums[1];
}


