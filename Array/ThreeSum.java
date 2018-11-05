package Array;
import java.util.*;

class ThreeSun implements JavaRun{

static class Solution {
    public List<List<Integer>> threeSum(int[] nums) {
        List<List<Integer>> ans = new ArrayList<>();
        HashMap<Integer,Integer> map = new HashMap<Integer,Integer>();
        Arrays.sort(nums); int len = nums.length;
        if(len < 3) return ans;
        if(nums[0] > 0 || nums[len - 1] < 0) return ans;
        if(nums[0] == 0 && nums[len - 1] == 0){
            ans.add(new ArrayList<>(Arrays.asList(0, 0, 0)));
            return ans;
        }
        int negcount = 0;
        for(int i = 0; i < len; i++){
            if(nums[i] <= 0) ++negcount;
            map.put(nums[i], i);
        }
        for(int i = 0; i < negcount;){
            for(int j = i + 1; j < len; ){
                int target = - nums[i] - nums[j];
                if(map.containsKey(target) && map.get(target) > j) {
                    ans.add(new ArrayList<>(Arrays.asList(nums[i], nums[j], target)));
                    j = map.get(nums[j]) + 1;
                }
                else
                    ++j;
            }
            i = map.get(nums[i]) + 1;
        }
        return ans;
    }
}

public void run(){
    int[] array = {-1, 0, 1, 2, -1, -4};
    
}

}