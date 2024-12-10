class Solution {
    /*
        given sorted array (non-decreasing)
        pivot k => [nums[k], nums[k+1], ..., nums[n-1], nums[0], nums[1], ..., nums[k-1]]
        e.g : [0,1,2,4,4,4,5,6,6,7] => [4,5,6,6,7,0,1,2,4,4]
        
        Given the array nums after the rotation and an integer target, return true if target is in nums, or false if         it is not in nums.
        
        (!) lets talk,
            [4,5,6,6,7,0,1,2,4,4] , when looking at any point at the array, there're two options or the left side is             sorted or the right side. ==> we can do binary_search at the sorted side;
            
            Target = 4 => mid = 7 => left is sorted = > you can do binary search at the left side O(logn)
            => not found? "throw the checked array and keep checking"

            Actually you cant solve the problem with O(logn) as a result of duplicates, according to chatgpt the best way to solve the problem is O(n); remove duplicate then search at the array ~ thanks GPT
            
            
            
            
        
    */
public:
    
    bool binarySearch(vector<int>& nums,int start,int end,int target){
        
        int left =  start;
        int right = end;
        
        while(left <= right){
            
            int mid = left + (right-left)/2;
            
            if(nums[mid] == target)
                return true;
            
            else if(nums[mid] > target)
                right = mid -1;
            else
                left = mid + 1;
        }
        return false;
    }
    
    bool search(vector<int>& nums, int target) {
        
        int start = 0 ;
        int end  = nums.size() -1;
        
        while(start <= end){
            
            int mid = start + (end-start)/2;
            
            if(nums[mid] == target)
                return true;

            if (nums[start] == nums[mid] && nums[mid] == nums[end]) {
                start++;
                end--;
                continue;
            }
            
            else if (mid >= 1 && nums[mid-1] <= nums[mid]  && nums[mid] <= nums[end])
            {
                //right side is sorted;
                if(binarySearch(nums,mid-1,end,target) == true)
                    return true;
                else
                    end = mid - 1;
            }
            else{
                //left side is sorted;
                if(binarySearch(nums,start,mid,target) == true)
                    return true;
                else
                    start = mid + 1;
            }
            
        }
        
        return false;
        
    }
};