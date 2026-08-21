class Solution {
public:
    int shortestPathAllKeys(vector<string>& grid) {
        map<char,int>mp;
        int c=1;
        int n=grid.size(),m=grid[0].size();
        queue<tuple<int,int,int,int>>q;
        for(int i=0;i<grid.size();i++){
            for(int j=0;j<grid[0].size();j++){
                if(grid[i][j]=='@')
                q.push({i,j,0,0});
                if(grid[i][j]>=65 && grid[i][j]<=90){
                    mp[grid[i][j]]=c;
                    mp[grid[i][j]+32]=c;
                    c++;
                }
            }
        }
        int x[4]={1,-1,0,0};
        int y[4]={0,0,1,-1};
        int size=mp.size()/2;
        vector<vector<vector<int>>>vis(n,vector<vector<int>>(m,vector<int>(1<<size,0)));
        int final=(1<<size)-1;
        while(!q.empty()){
            auto [i,j,st,mask]=q.front();
            q.pop();
            if(mask==final)
            return st;
            vis[i][j][mask]=1;
            for(int z=0;z<4;z++){
                int x1=i+x[z];
                int y1=j+y[z];
                if(x1>=0 && y1>=0 && x1<n && y1<m){
                    if(grid[x1][y1]=='#')
                    continue;
                    if((grid[x1][y1]=='.' || grid[x1][y1]=='@') && vis[x1][y1][mask]==0){
                        q.push({x1,y1,st+1,mask});
                        vis[x1][y1][mask]=1;
                    }
                    if(grid[x1][y1]>=65 && grid[x1][y1]<=90){
                            int p=mp[grid[x1][y1]]-1;
                            if((mask & (1<<p))!=0 && vis[x1][y1][mask]==0){
                                vis[x1][y1][mask]=1;
                                q.push({x1,y1,st+1,mask});
                            }
                    }
                    if(grid[x1][y1]>=97 && grid[x1][y1]<=122 ){
                        int p=mp[grid[x1][y1]]-1;
                        int newMask=mask | (1<<p);
                        if(!vis[x1][y1][newMask]){
                        vis[x1][y1][newMask]=1;
                        q.push({x1,y1,st+1,newMask});
                        }
                    }
                }
            }
        }
        return -1;
    }
};