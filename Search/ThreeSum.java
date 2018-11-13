package Search;
import java.util.*;
import JavaInterface.JavaRun;

public class ThreeSum implements JavaRun{

static class Solution {
    public List<List<Integer>> threeSum(int[] nums) {
        List<List<Integer>> ans = new ArrayList<>();
        int len = nums.length;
        if(len < 3)  return ans;
        Arrays.sort(nums);
        for(int i = 0; i < len - 2; ++i){
            if(i > 0 && nums[i - 1] == nums[i])
                continue;
            int left = i + 1, right = len - 1, target = -nums[i];
            while(left < right){
                int sum = nums[left] + nums[right];
                if(sum > target)
                    --right;
                else if(sum < target)
                    ++left;
                else{
                    ++ left; --right;
                    while(left < right && nums[left] == nums[left - 1])
                        ++left;
                    while(right > left && nums[right] == nums[right + 1])
                        --right;
                    ans.add(Arrays.asList(nums[i], nums[left - 1], nums[right + 1]));
                }
            }
        }
        return ans;
    }
}

public void run(){
    int[] array = {-1, 0, 1, 2, -1, -4};
    int[] array1 = {0, 0, 0};
    System.out.println(new Solution().threeSum(array));
    System.out.println(new Solution().threeSum(array1));
    
}

}