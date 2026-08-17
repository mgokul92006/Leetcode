class Solution {
public:
    int x[4]={1,-1,0,0};
    int y[4]={0,0,1,-1};
    int c=0;
    void back(int i,int j,vector<vector<int>>&grid,vector<vector<int>>&vis,int cell){
        if(grid[i][j]==2){
            if(cell+1==0)
            c++;
            return;
        }
        for(int z=0;z<4;z++){
            int x1=x[z]+i;
            int y1=y[z]+j;
            if(x1>=0 && y1>=0 && x1<grid.size() && y1<grid[0].size()){
                if(vis[x1][y1]==0 && grid[x1][y1]!=-1){
                    vis[x1][y1]=1;
                    back(x1,y1,grid,vis,cell-1);
                    vis[x1][y1]=0;
                }
            }
        }
    }
    int uniquePathsIII(vector<vector<int>>& grid) {
        int cell=0;
        for(int i=0;i<grid.size();i++){
            for(int j=0;j<grid[0].size();j++){
                if(grid[i][j]==0)
                cell++;
            }
        }
        vector<vector<int>>vis(grid.size(),vector<int>(grid[0].size(),0));
        for(int i=0;i<grid.size();i++){
            for(int j=0;j<grid[0].size();j++){
                if(grid[i][j]==1){
                vis[i][j]=1;
                back(i,j,grid,vis,cell);
                }
            }
        }
        return c;
    }
};