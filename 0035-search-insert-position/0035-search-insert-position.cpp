class Solution {
    /*
    * This problem can be solved by adapting the Binary Search algorithm.
    * An interesting observation is that the array contains only distinct integers.
    * As a result, the target value, if not found, will always be surrounded by 
    * larger and smaller values in the sorted array.
    */
    
public:
    int searchInsert(vector<int>& nums, int target) {
    
        int n = nums.size();
        int left = 0;
        int right = n -1;
        int mid;
        
        if(nums.size() == 0)
            return 0;
        
        while(left <= right){
            
             mid = left + (right - left)/2;
            
            if(nums[mid] == target)
                return mid;
            
            else if(mid >0 && nums[mid] > target && target > nums[mid -1 ])
                return mid;
            
            else if(target > nums[mid])
                left = mid + 1;
            else
                right = mid -1;
        }
        
        if(mid > 0)
            return n;
        return (nums[0] < target)? 1:0;
    }
};