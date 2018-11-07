class Solution {
    private int binarySearch(int [] nums, int indexStart, int indexEnd, int target){
        if(target > nums[indexEnd] || target < nums[indexStart])
            return -1;
        while(indexStart <= indexEnd){
            int mid = (indexStart + indexEnd)/2;
            if(nums[mid] > target)
                indexEnd = mid - 1;
            else if(nums[mid] < target)
                indexStart = mid + 1;
            else{
                return mid;
            }
        }
        return -1;
    }

    public int search(int[] nums, int target) {
        int left = 0, right = nums.length - 1;
        if(right == left) return (target == nums[0])? 0: -1;
        while(right > left){
            if(target == nums[left]) return left;
            if(target == nums[right]) return right;
            if(nums[left] < nums[right]) return binarySearch(nums, left, right, target);
            int mid = (left + right)/2;
            if(target == nums[mid]) return mid;
            if(nums[mid] > nums[left]){
                if(target > nums[left] && target < nums[mid])
                    return binarySearch(nums, left, mid, target);
                else{
                    left = mid;
                    continue;
                }
            }
            else{
                if(target > nums[mid] && target < nums[right])
                    return binarySearch(nums, mid, right, target);
                else{
                    right = mid;
                    continue;
                }
            }
        }
        return -1;
    }
}