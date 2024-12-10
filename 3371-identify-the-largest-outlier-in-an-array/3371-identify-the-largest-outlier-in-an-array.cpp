class Solution {

    /*
        - Consider any a_i is outliner, Calculate the array elements sum, {Sum = segma(a_i)| forAll a_i belong to the array\outliner}. what we know? the sum is equal 2*(some A_i not outliner);
        - now lets iterate over and check if (sum/2) exist? yes awesome we found an outlier and n-2 elements with sum.
        - return the max outlier;

        time complexity = O(n) - calculate sum & 2 more iterates over the array, space complexity O(n) in case i decided to use unorder_map. Can i optimize?
        Not sure, i will think about that after implementing the solution;

    */
public:
    int getLargestOutlier(vector<int>& nums) {

        unordered_map<int,int> elements;
        int n = nums.size();
        int sum = 0;
        int maxOutLiner = INT_MIN;

        //Fill existing elements & calculate sum
        for(int i = 0 ; i < n;i++){
            elements[nums[i]]++;
            sum += nums[i];
        }

        for(int i = 0 ; i < n ; i++){
            int sumWithOutBoarder = sum-nums[i];
            elements[nums[i]]--;
            if(sumWithOutBoarder%2 == 0)
                if(elements[sumWithOutBoarder/2] >= 1)
                        maxOutLiner = max(maxOutLiner,nums[i]);
            elements[nums[i]]++;

        }
        return maxOutLiner;
    }
};