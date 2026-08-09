class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        int row=grid.size();
        int col=grid[0].size();
        int cnt=0;
        for(int i=0;i<row;i++){
            for(int j=0;j<col;j++){
                if(grid[i][j]=='1'){
                    cnt++;
                    dfs(i,j,row,col,grid);
                }
            }
        }
        return cnt;
    }
    void dfs(int r,int c,int row,int col,vector<vector<char>>& grid){
        if(r<0 || r>=row||c<0||c>=col||grid[r][c]=='0'){
            return;
        }
        grid[r][c]='0';
        dfs(r+1,c, row, col, grid);
        dfs(r,c+1, row, col, grid);
        dfs(r-1,c, row, col, grid);
        dfs(r,c-1, row, col, grid);
    }
};
