class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        int n=board.size();
        int m=board[0].size();
        for(int i=0;i<n;i++){
            bool seen[10]={};
            for(int j=0;j<m;j++){
                if(board[i][j]=='.')continue;
                int e=board[i][j]-'0';
                if(seen[e]==true){
                    return false;
                }else{
                    seen[e]=true;
                }
            }
        }
        for(int j=0;j<m;j++){
            bool seen[10]={};
            for(int i=0;i<n;i++){
                if(board[i][j]=='.')continue;
                int e=board[i][j]-'0';
                if(seen[e]){
                    return false;
                }else{
                    seen[e]=true;
                }
            }
        }
        for(int i=0;i<9;i+=3){
            for(int j=0;j<9;j+=3){
                bool seen[10]={};
                for(int r=i;r<i+3;r++){
                    for(int c=j;c<j+3;c++){
                        if(board[r][c]=='.')continue;
                        int e=board[r][c]-'0';
                        if(seen[e]){
                            return false;
                        }
                        seen[e]=true;
                    }
                }
            }
        }
        return true;
    }
};