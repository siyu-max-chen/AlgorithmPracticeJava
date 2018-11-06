package Array;
import java.util.*;

public class RemoveElement{
    class Solution {
        public int removeElement(int[] nums, int val) {
            int len = nums.length; int elemNums = -1;
            if(len == 0) return 0;
            if(len <=1 && nums[0] != val) return 1;
            for(int i = 0; i < len; ++i){
                if(nums[i] != val)
                    nums[++elemNums] = nums[i];
            }
            return ++elemNums;
        }
    }
}