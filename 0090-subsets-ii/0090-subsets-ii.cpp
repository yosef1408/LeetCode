class Solution {
    
    
    void backtrack(vector<int>&nums,vector<vector<int>>& res,int start,vector<int> currSet ){
        
        if(start == nums.size())
            return;
        
        unordered_map<int, bool> seen;

        for(int i = start; i < nums.size(); i++){
            
            if(seen[nums[i]] == true){
                continue;
            }
            
            currSet.push_back(nums[i]);
            seen[nums[i]] = true;
            res.push_back(currSet);
            backtrack(nums,res,(i+1),currSet);
            
            currSet.pop_back();
        }
    }
    
    
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        
        vector<vector<int>> res;
        res.push_back({});
        sort(nums.begin(), nums.end());

        backtrack(nums,res,0,{});
        
        return res;
        
    }
};