class Solution {
public:
    /* (A)
        - Naive soultion will use backtracking to check all possibilities - each time have two steps, and you have ignore the
          obstacle. ==> time & space complexity = O(2^(m+n)) .

        (B)
        - we can solve the problem using DP - lets take a look at grid[i][j] , you can reach it using right step or bottom step;
        therfore, grid[i][j] = possibilities(grid[i][j-1]) + possibilities(grid[i-1][j]); take into considiration the bounds &  limits; 

        time & space complexity O(M*N).

        */
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {

        int m = obstacleGrid.size();
        int n = obstacleGrid[0].size();
        vector<vector<int>> dp (m,vector<int>(n,0));

        //Initialize
        dp[0][0] = (obstacleGrid[0][0] == 1)? 0 : 1;

        //Fill dp matrix
        for(int i = 0 ; i < m ; i++)
        {
            for(int j = 0 ; j < n ;j++){
                
                if(i == 0 && j == 0){
                    continue;
                }
                else if(obstacleGrid[i][j] == 1){
                        dp[i][j] = 0;
                }
                else if (i-1 >= 0 && j-1 >= 0)
                    dp[i][j] = dp[i-1][j] + dp[i][j-1];
                else if( i -1 < 0 && j-1 >= 0)
                    dp[i][j] = dp[i][j-1];
                else if( i -1 >= 0 && j-1<0)
                    dp[i][j] = dp[i-1][j];
            }
        }
        return dp[m-1][n-1];

        
    }
};