package DFS;
import java.util.*;
import JavaInterface.JavaRun;

class Permutations{
    class Solution {
        boolean[] used;
        List<List<Integer>> ans;
        int len;
        List<Integer> tempList;
        private void dfs(int[] nums){
            if(len == tempList.size())
                ans.add(new ArrayList<>(tempList));
            else{
                for(int i = 0; i < len; ++i){
                    if(used[i]) continue;
                    used[i] = true;
                    tempList.add(nums[i]);
                    dfs(nums);
                    used[i] = false;
                    tempList.remove(tempList.size() - 1);
                }
            }
        }
        public List<List<Integer>> permute(int[] nums) {
            ans = new ArrayList<>();
            len = nums.length;
            used = new boolean[len];
            tempList = new ArrayList<>();
            dfs(nums);
            return ans;
        }
    }

    public static void main(String[] args){
        Lc lc = new Lc();
        Solution sol = lc.new Solution();
        int[] array = {1, 2, 3};
        //List<List<Integer>> ans = new Solution().fourSum(array, 0);
        System.out.println(sol.permute(array));
    }
}