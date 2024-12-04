class Solution {
    /* the problem is about finding the shortest path from start point(grid[0][0]) and end point (grid[m-1][n-1]);
       one way to solve it using DP , DP[i][j] - the shortest path to reach grid[i][j]; there for DP[i][i] = min(DP[i-1][j],DP[i][j-1]) + grid[i][j]; == min(down->t,right->t)+ grid[t];
       time & space complexity => O(m*n); iterating through all the matrix;
       */
public:
    int minPathSum(vector<vector<int>>& grid) {

        int m = grid.size();
        int n = grid[0].size();
        vector<vector<int>> dp(m,vector<int>(n,0));

        //Initialize:
        dp[0][0] = grid[0][0];

        for(int i = 0 ; i < m ;i++)
            for(int j = 0 ;j < n ;j++)
            {
                if(i == 0 && j == 0)
                    continue;
                else if( j-1 < 0 )
                    dp[i][j] = dp[i-1][j]+grid[i][j];
                else if( i-1 < 0)
                    dp[i][j] = dp[i][j-1]+grid[i][j];
                else
                    dp[i][j] = min(dp[i-1][j],dp[i][j-1]) + grid[i][j];
            }
        return dp[m-1][n-1];
        
    }
};