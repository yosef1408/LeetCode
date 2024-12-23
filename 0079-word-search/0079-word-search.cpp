class Solution {
    /*
    - the question is kind of DFS, we find the first trigger ( first letter) then run DFS in hope to find the word.
    - time complexity, at worst case travling from each cell(node) String sizes steps, therefore, if the matrix size nXm
    - time complexity is O(nm) beacuse the word length is max 15;
    - space complexity O(1), there're no need for additional space;
    */
    
    bool dfs(int i , int j, int curr ,string word,vector<vector<char>>& board){
        
        if(curr == word.size())
            return true;
        
        if (i < 0 || i >= board.size() || j >= board[0].size() || j < 0) //Out of bounds
            return false;
        
        if(board[i][j] == '1')
            return false;
        
        if(word[curr] == board[i][j]){ // Match
            //sting subword = word.substr(1);
            curr++;
            char temp = board[i][j];
            board[i][j] = '1';
            bool res =  ( dfs(i,j+1,curr,word,board) || dfs(i,j-1,curr,word,board) ||dfs(i+1,j,curr,word,board) || 
                    dfs(i-1,j,curr,word,board));
            board[i][j] = temp;
            return res;
        }
        
        return false;
    }
public:
    bool exist(vector<vector<char>>& board, string word) {
        
        int m = board.size();
        int n = board[0].size();
        
        for(int i = 0 ;i < board.size(); i++){
            for(int j = 0 ; j < board[0].size();j++){

                if(board[i][j] == word[0])
                    if(dfs(i,j,0,word,board))
                        return true;
            }
    }
                return false;
    }

};