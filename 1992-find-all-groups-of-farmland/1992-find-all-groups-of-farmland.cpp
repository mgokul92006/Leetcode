class Solution {
public:
    int x[4]={1,-1,0,0};
    int y[4]={0,0,1,-1};
    void bfs(vector<vector<int>>&land,vector<vector<int>>&vis,vector<vector<int>>&ans,int i,int j){
        vis[i][j]=1;
        vector<int>ans1;
        ans1.push_back(i);
        ans1.push_back(j);
        queue<tuple<int,int>>q;
        q.push({i,j});
        int l=-1,r=-1;
        while(!q.empty()){
            auto [i,j]=q.front();
            q.pop();
            l=i,r=j;
            for(int z=0;z<4;z++){
                int x1=x[z]+i;
                int y1=y[z]+j;
                if(x1>=0 && y1>=0 && x1<land.size() && y1<land[0].size() && land[x1][y1]==1 && vis[x1][y1]==0){
                    vis[x1][y1]=1;
                    q.push({x1,y1});
                }
            }
        }
        ans1.push_back(l);
        ans1.push_back(r);
        ans.push_back(ans1);
    }
    vector<vector<int>> findFarmland(vector<vector<int>>& land) {
        vector<vector<int>>ans;
        vector<vector<int>>vis(land.size(),vector<int>(land[0].size(),0));
        for(int i=0;i<land.size();i++){
            for(int j=0;j<land[i].size();j++){
                if(land[i][j]==1 && vis[i][j]==0){
                    bfs(land,vis,ans,i,j);
                }
            }
        }
        return ans;
    }
};