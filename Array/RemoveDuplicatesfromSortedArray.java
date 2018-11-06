package Array;
import java.util.*;

public class RemoveDuplicatesfromSortedArray{
    class Solution {
        public int removeDuplicates(int[] nums) {
            int len = nums.length;
            if(len <= 1) return len;
            int currIndex = 0; int ans = 1;
            for(int i = 1; i < len; i++){
                if(nums[i] != nums[currIndex]){
                    nums[++currIndex] = nums[i];
                }
            }
            return ++currIndex;
        }
    }
}