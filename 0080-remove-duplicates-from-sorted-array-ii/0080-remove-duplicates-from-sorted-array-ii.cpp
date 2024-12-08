class Solution {
    /*
    Lets talk,
    - time complexity is O(n) because you have to pass over all the array elements, u cant less even if it sorted.
    - space complexity O(1), therefore i cant allocate another array (in-place);
    
    Solution:
        - given : [1,1,1,2,2,3] lets hold pointer at the current array( which keep increasing,) and a pointer to indicate where to insert the element; in addition  we keep a bool variable appearedTwice which indicate if the following int appeared twice all ready.
        
        
        [1,1,1,2,2,3] ==> arrPointer -> 0, appearedTwice -> false, insertPointer -> 0;
        --> checking if it's legal to insert --> if is nums[inserPointer]=nums[arrPointer] & arrPointer++;
        ...
        
        
    
    */
public:
    int removeDuplicates(vector<int>& nums) {
        
        int insertPointer = 1 , i = 1;
        bool appearedTwice = false;
        int n = nums.size();
        
        //EdgeCase:
        if(n == 0 || n == 1 || n==2)
            return n;
        
        for(;i<n;i++)
        {
            if(appearedTwice == false && nums[i-1] == nums[i]){
                appearedTwice = true;
                nums[insertPointer] =nums[i];
                insertPointer++;
            }
            else if(nums[i-1] == nums[i] && appearedTwice){
                continue;
            }
            else if(nums[i-1] != nums[i] )
            {
                appearedTwice = false;
                nums[insertPointer] =nums[i];
                insertPointer++;

            }
            
        }
        
        return insertPointer;
        
    }
};