class Solution {
    /*
     actually, i can solve this by counting the numbers of apperance of each color, holding three variables (redCount,whiteCount,blueCount); then override the nums array;

     time complexity => O(n) , space complexity O(3) = O(1);
    */
public:
    void sortColors(vector<int>& nums) {

        int n = nums.size();

        int redCount = 0, whiteCount = 0 , blueCount = 0;

        if(n != 1){

       //Counting the appearnce of each element;
        for(int i = 0 ; i <n ;i++)
        {
            if(nums[i] == 0)
                redCount++;
            else if(nums[i] == 1)
                whiteCount++;
            else
                blueCount++;
        }

        for(int i = 0 ; i < redCount;i++)   
            nums[i] = 0;

        for(int i = redCount ; i < redCount+whiteCount;i++)
            nums[i] = 1;

        for(int i = redCount+whiteCount ; i <redCount+whiteCount+blueCount;i++)
            nums[i] = 2; 
     
        }

    
    }
};