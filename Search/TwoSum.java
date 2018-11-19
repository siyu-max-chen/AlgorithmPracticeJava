package Search;
import java.util.*;
import JavaInterface.JavaRun;

public class TwoSum implements JavaRun{

/*
    题号：1
    已完成
*/
static class Solution {
    public int[] twoSum(int[] nums, int target) {
        // Simple way by using Hashmap 
        HashMap<Integer, Integer> map = new HashMap<Integer, Integer>();
        for(int i = 0; i < nums.length; ++i){
            int key = target - nums[i];
            if(map.containsKey(key))
                return new int[] {map.get(key), i};
            map.put(nums[i], i);
        }
        throw new IllegalArgumentException("No two sum solution");
    }

    public int[] twoSumOther(int[] nums, int target) {
        // Not using Hashmap, N logN
        int[] numsCopy = nums;
        Arrays.sort(nums);
        int left = 0, right = nums.length - 1; boolean initial = true;
        if(nums[left] > target || nums[right] < 0) 
            throw new IllegalArgumentException("No two sum solution");
        int min = nums[left], max = nums[right];
        int[] Map = new int[max - min + 1];
        for(int i = 0; i < right + 1; ++i){
            Map[numsCopy[i] - min] = i;
        }
        while(left < right){
            int sum = nums[left] + nums[right];
            if(sum > target)
                --right;
            else if(sum < target)
                ++left;
            else{
                return new int[]{ Map[nums[left] - min], Map[nums[right] - min]};
            }
        }
        throw new IllegalArgumentException("No two sum solution");
    }
}

public void run(){
    int[] nums = {3, 2, 3};
    int target = 6;
    int[] ans = new Solution().twoSum(nums, target);
    System.out.println("result: ");
    System.out.println(ans[0] + " " + ans[1]);
    ans = new Solution().twoSumOther(nums, target);
    System.out.println("result: ");
    System.out.println(ans[0] + " " + ans[1]);
}

}