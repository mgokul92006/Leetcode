class Solution {
public:
    int x[4]={1,-1,0,0};
    int y[4]={0,0,1,-1};
    bool dfs(vector<vector<char>>&board,string& word,int i,int j,vector<vector<int>>&vis,int k){
        if(k==word.size())
        return true;
        vis[i][j]=1;
        for(int z=0;z<4;z++){
            int x1=i+x[z];
            int y1=j+y[z];
            if(x1>=0 && x1<board.size() && y1>=0 && y1<board[i].size() && vis[x1][y1]==0 && board[x1][y1]==word[k]){
                if(dfs(board,word,x1,y1,vis,k+1))
                return true;
            }
        }
        vis[i][j]=0;
        return false;
    }
    bool exist(vector<vector<char>>& board, string word) {
        vector<vector<int>>vis(board.size(),vector<int>(board[0].size(),0));
        for(int i=0;i<board.size();i++){
            for(int j=0;j<board[0].size();j++){
                if(board[i][j]==word[0] && !vis[i][j]){
                    if(dfs(board,word,i,j,vis,1)){
                        return true;
                    }
                }
            }
        }
        return false;
    }
};