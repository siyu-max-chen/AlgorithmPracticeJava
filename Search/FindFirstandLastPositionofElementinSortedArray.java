class Solution {
    public int[] searchRange(int[] nums, int target) {
        int left = 0; int right = nums.length - 1;
        int[] ans = new int[2];
        if(right < 0) {
            ans[0] = -1; ans[1] = -1;
            return ans;
        }
        if(right == 0){
            if(nums[0] == target){
                ans[0] = 0; ans[1] = 0;
                return ans;
            }
            else{
                ans[0] = -1; ans[1] = -1;
                return ans;
            }
        }
        while(left <= right){
            int mid = (left + right)/2;
            if(nums[mid] > target)
                right = mid - 1;
            else if(nums[mid] < target)
                left = mid + 1;
            else{
                int leftPivot = mid - 1;
                while(leftPivot >= left){
                    if(nums[leftPivot] != target)
                        break;
                    --leftPivot;
                }
                ans[0] = ++leftPivot;
                int rightPivot = mid + 1;
                while(rightPivot <= right){
                    if(nums[rightPivot] != target)
                        break;
                    ++rightPivot;
                }
                ans[1] = --rightPivot;
                return ans;
            }
        }
        ans[0] = -1; ans[1] = -1;
        return ans;
    }
}