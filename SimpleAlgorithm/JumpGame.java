package SingleAlgorithm;
import java.util.*;
import JavaInterface.JavaRun;

public class JumpGame{
    class Solution {
        public boolean canJump(int[] nums) {
            // 直观方法，思路很直观！！！
            int len = nums.length;
            if(len < 2) return true;
            int max = nums[0];
            for(int i = 1; i < 1 + max; ++i){
                max = Math.max(max, i + nums[i]);
                if(max >= len - 1) return true;
            }
            return false;
        }

        public boolean canJumpBack(int[] nums) {
            // 从后往前检查，思路很巧妙，如果能回到0，则为真！
            int lastPos = nums.length - 1;
            for(int i = nums.length - 1; i >= 0; --i){
                if(nums[i] + i >= lastPos)
                    lastPos = i;
            }
            return lastPos == 0;
        }

        private boolean dfs(int[] nums, int index, int len, int rightAready){
            // DFS方法，比较愚蠢，注意的是一定要防止重复查找！！！
            if(len - index - 1 <= nums[index]) return true;
            if(index + nums[index] < rightAready) return false;
            for(int i = rightAready + 1; i <= index + nums[index]; ++ i ){
                if(dfs(nums, i, len, index + nums[index])) return true;
            }
            return false;
        }
        public boolean canJumpDfs(int[] nums) {
            // DFS方法，比较愚蠢，注意的是一定要防止重复查找！！！
            int len = nums.length;
            if(nums == null || len == 0) return false;
            return dfs(nums, 0, len,0);
        }

    }

}