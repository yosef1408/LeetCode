class Solution {

    void dfs(vector<vector<char>>& grid, int node_i,int node_j){

        //out of bounds, visted ..
        if(node_i < 0 || node_j <0 || node_i >= grid.size()|| node_j >= grid[0].size() || grid[node_i][node_j] == 'V' || grid[node_i][node_j] =='0')
            return;

        grid[node_i][node_j] = 'V';
        
        dfs(grid,(node_i+1),node_j); //Down
        dfs(grid,(node_i-1),node_j); //UP
        dfs(grid,(node_i),node_j+1); //right
        dfs(grid,(node_i),node_j-1); //left

    }
public:
    int numIslands(vector<vector<char>>& grid) {
        /*
        1. each time you can extend extend - that increase the chances to be island;
        2. after being max increase- congra you're island; - assume not => you can extend;
        3.keep going and find the next island;

        Algorithm:
            - return the number of strong connected  compnent at the graph. run dfs;
            from each node and  maintain visted matrix; return the number of SCC;
               ==> complexity: Time and space: nested for O(m*n) - DFS do final steps as number of node;
               ==> 
        */
        int scc = 0;
        int m = grid.size(), n= grid[0].size();
        for(int i = 0 ; i < m ; i++ )
            for(int j = 0 ; j < n ; j++)
            {
                if(grid[i][j] == '1')
                {
                    dfs(grid,i,j);
                    scc++;
                    
                }

            }
        return scc;
    }
};