class Solution {
    
    void combine_Aux(vector<vector<int>>& result,int start,vector<int>comb,int n, int k)
    {
        if(comb.size() == k)
        {
            result.push_back(comb);
            return;
        }
        
        if(start > n)
            return;
        
        for(start;start <= n;start++)
        {
            comb.push_back(start);
            combine_Aux(result,(start+1),comb,n,k);
            comb.pop_back();
            
            /*
                                 1                       2
                                                
                                 
                        1,2     1,3     1,4        2,3      2,4         3,4 
            */
        }
        
    }
public:
    vector<vector<int>> combine(int n, int k) {
        
        vector<vector<int>> result;
        
        combine_Aux(result,1,{},n,k);
        
        return result;
        
        
    }
};