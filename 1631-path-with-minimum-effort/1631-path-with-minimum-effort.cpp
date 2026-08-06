class Solution {
public:
    int x[4]={1,-1,0,0};
    int y[4]={0,0,1,-1};
    bool check(int p,vector<vector<int>>&grid){
        int n=grid.size();
        int m=grid[0].size();
        vector<vector<int>>vis(n,vector<int>(m,0));
        queue<pair<int,int>>q;
        q.push({0,0});
        vis[0][0]=0;
        while(!q.empty()){
            auto [i,j]=q.front();
            q.pop();
            for(int z=0;z<4;z++){
                int x1=i+x[z];
                int y1=j+y[z];
                if(x1>=0 && x1<n && y1>=0 && y1<m && !vis[x1][y1] && abs(grid[i][j]-grid[x1][y1])<=p){
                    if(x1==n-1 && y1==m-1)
                    return 1;
                    vis[x1][y1]=1;
                    q.push({x1,y1});
                }
            }
        }
        return 0;
    }
    int minimumEffortPath(vector<vector<int>>& heights) {
        int l=0;
        int h=1000000;
        int ans=0;
        while(l<=h){
            int m=(l+h)/2;
            if(check(m,heights)){
                ans=m;
                h=m-1;
            }
            else
                l=m+1;
        }
        return ans;
    }
};