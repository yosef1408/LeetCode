class Solution {
    
    /*
    
    given sorted array, e.g:[0,0,1,1,1,2,2,3,3,4] we want to remove the duplicate elements;
    lets maintain two pointers; the first iterate over the array; the secound is resposible for sorting in place, 
    to be more accurate it's point to the insert position;
    
    the last things we have to consider is checking if the number allready insered;
    
    time complexity O(n), space complexity o(1) - in place;
    
    
    */
public:
    int removeDuplicates(vector<int>& nums) {
        
        int n = nums.size();
        int insertPointer = 1;
        
        for(int i = 1 ; i<n;i++){
            
            if(nums[i] == nums[i-1])
                continue;
            else{
                nums[insertPointer] = nums[i];
                insertPointer++;
            }
        }
        
        return insertPointer;
        
    }
};