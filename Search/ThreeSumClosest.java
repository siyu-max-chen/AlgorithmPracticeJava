package Search;
import java.util.*;
import JavaInterface.JavaRun;

public class ThreeSumClosest implements JavaRun{

static class Solution {
    public int threeSumClosest(int[] nums, int target) {
        int ans = 0, len = nums.length;
        Arrays.sort(nums);
        ans = nums[0] + nums[1] + nums[2];
        for(int i = 0; i < len - 2; ++i){
            if(i > 0 && nums[i - 1] == nums[i])
                continue;
            int left = i + 1, right = len - 1, targetOther = target - nums[i];
            while(left < right){
                int sum = nums[left] + nums[right];
                if(sum > targetOther){
                    --right;
                }
                else if(sum < targetOther){
                    ++left;
                }
                else{
                    return target;
                }
                if(Math.abs(sum - targetOther) < Math.abs(ans - target)){
                    ans = sum + nums[i];
                }
            }
        }
        return ans;
    }
}


public void run(){
    int[] array = {-1, 0, 1, 2, -1, -4};
    int[] array1 = {0, 0, 0};
    System.out.println(new Solution().threeSumClosest(array, 1));
    System.out.println(new Solution().threeSumClosest(array1, 1));
    
}

}