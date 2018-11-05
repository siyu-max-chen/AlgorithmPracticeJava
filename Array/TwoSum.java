package SimpleAlgorithm;
import java.util.*;
import JavaInterface.JavaRun;

public class TwoSum implements JavaRun{

static class Solution {
    public int[] twoSum(int[] nums, int target) {
        HashMap<Integer, Integer> map = new HashMap<Integer, Integer>();
        for(int i = 0; i < nums.length; i++){
            int key = target - nums[i];
            if(map.containsKey(key))
                return new int[] {map.get(key), i};
            map.put(nums[i], i);
        }
        throw new IllegalArgumentException("No two sum solution");
    }
}

public void run(){
    int[] nums = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12};
    int target = 12;
    int[] ans = new Solution().twoSum(nums, target);
    System.out.println("result: ");
    System.out.println(ans[0] + " " + ans[1]);
}

}