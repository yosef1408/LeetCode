class Solution {
    
    void backtrack(vector<vector<int>>& res,vector<int>& nums,int start,vector<int> subset){
        
        if(start == nums.size()){
            return;
        }
        
        
        for(int i=start ; i < nums.size();i++){
            
            subset.push_back(nums[i]);
            res.push_back(subset);
            backtrack(res,nums,(i+1),subset);
            subset.pop_back();
        }
    }
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        

        vector<vector<int>> res;
        res.push_back({});
        
        backtrack(res,nums,0,{});
        
        return res;
        
    }
};