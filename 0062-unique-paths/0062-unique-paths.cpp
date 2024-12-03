class Solution {
public:
/*
    Idea(1):
    1- we can solve the problem using backtracking approach, as follow each time we have 2 options (right,down)
    => time and space complexity for that solution O(2^(m+n)) as a vector of (m+n) cells and each cell may be right or down;

    Idea(2):
    Dynamic programin: our progress is right or down , therefore, we can reach [i][j] from [i-1][j] or [i][j-1] => as a result of that Answer([i][j]) = Answer[i-1][j] + Answer[i][j-1];

    time complexity => O(n*m), space complexity = O(n*m)
*/
    int uniquePaths(int m, int n) {

        vector<vector<int>> dp(m,vector<int>(n,0));

        //Initalization:
        dp[0][0]=1;
        
        //Fill the dp matrix
        for(int i = 0 ; i < m ; i++)
        {
            for(int j = 0 ; j < n; j++)
            {
                if(j-1 < 0 && i -1 >= 0 )
                    dp[i][j] = dp [i-1][j];
                else if( j-1 >= 0 && i-1 <0)
                    dp[i][j] = dp[i][j-1];
                else if( j-1 < 0 && i-1 < 0)
                    continue;
                else
                    dp[i][j] = dp[i-1][j]+dp[i][j-1];
                 
            }
        }

        return dp[m-1][n-1];

    }
};