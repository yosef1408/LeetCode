class Solution {

    /*
    - the trick at the question to detect which "0" is orginal and which is not.
    - lets take a look at the following matrix:

        0   0   1   0
        1   1   1   1
        1   1   1   1

    - A naive solution which change immediatley all the rows and columns to zero will result the enitre matrix to be "ZERO"
    - the intersting of this question is to solve it in-place actually O(1) space complexity;

    - i'll solve it with O(m+n) space complexity then try to solve it with O(1), which is much harder;

    
        int m = matrix.size();
        int n = matrix[0].size();

        vector<bool> setToZero(m+n+1,false);

        for(int i = 0 ; i < m ; i++)
            for(int j = 0 ; j < n ;j++)
            {
                if(matrix[i][j] == 0){
                    setToZero[i] = true;
                    setToZero[j+m] = true;
                }
            }
        
        //Reset Rows;
        for(int i = 0 ; i < m ;i++)
        {
            if(setToZero[i])
                for(int j=0 ; j < n ;j++)
                    matrix[i][j] = 0;
        }

        //Reset Columns;
        
        for(int i = m ; i < n+m ;i++)
        {
            if(setToZero[i])
                for(int j=0 ; j < m ;j++)
                    matrix[j][i-m] = 0;
        }

    """" now lets try to solve it at O(1) space complexity, the time complexity will remain the same O(m*n);
        I'll use the first row & column as a marker; in addition of them i will use two variables to store firstRow, firstColumn;

        lets take a look at the following example:

        1   1   0
        1   0   1
        1   1   1
        ===================>
        
        firstColumn = 1(indicate no need to reset); firstRow = 0 ; matrix[0][1] = 0 (Reset),matrix[1][0] = 0;


    */
public:
    void setZeroes(vector<vector<int>>& matrix) {

        bool firstRowZero = false , firstColZero = false;
        int m = matrix.size();
        int n = matrix[0].size();

        //Initalize, 
        for(int i = 0 ; i < m ;i++)
            if(matrix[i][0] == 0)
                firstColZero = true;

        for(int j = 0 ; j < n ;j++)
            if(matrix[0][j] == 0)
                firstRowZero = true;

        //checking the rest of the matrix;

        for(int i = 1 ; i < m ; i++)
            for(int j = 1 ; j < n ;j++)
                if(matrix[i][j] == 0)
                    matrix[i][0] = matrix[0][j] = 0;
        

        for(int i = 1 ; i < n ;i++)
            if(matrix[0][i] == 0)
                for(int j = 1 ; j<m ; j++)
                    matrix[j][i] = 0;
        
        for(int i = 1 ; i < m ;i++)
            if(matrix[i][0] == 0)
                for(int j = 1 ; j<n ; j++)
                    matrix[i][j] = 0;   

        if(firstRowZero)
            for(int i = 0 ; i < n ;i++)
                matrix[0][i] = 0;
        
        if(firstColZero)
            for(int i = 0 ; i < m ;i++)
                matrix[i][0] = 0;

           


    }
};