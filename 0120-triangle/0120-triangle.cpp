class Solution {
    /*
    - the best way to solve the problem is using DP, building a matrix of triangle_Hieght * max nodes at the base;
    - time complexity as space complexity moving at the matrix
    
    */
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        
        int m = triangle.size();
        int n = triangle[m-1].size();
        
        vector<vector<int>> dp (m,vector<int>(n,0));
        
        for(int i = m - 1 ; i >=0;i--)
            for(int j = 0;  j < triangle[i].size();j++){
                
                if(i == m - 1) //Last Layer
                    dp[i][j] = triangle[i][j];
                else{
                    dp[i][j] = triangle[i][j] +min(dp[i+1][j],dp[i+1][j+1]);
                }
                
            }
        
        return dp[0][0];
        
    }
};