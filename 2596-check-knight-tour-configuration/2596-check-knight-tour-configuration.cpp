class Solution {
public:
    int x[8]={-1,-2,-2,-1,1,2,2,1};
    int y[8]={-2,-1,1,2,2,1,-1,-2};
    bool bfs(vector<vector<int>>& grid){
        int n=grid.size();
        vector<int>vis(n*n,0);
        queue<pair<int,pair<int,int>>>q;
        q.push({0,{0,0}});
        vis[0]=1;
        while(!q.empty()){
            int num=q.front().first;
            int i=q.front().second.first;
            int j=q.front().second.second;
            q.pop();
            if(num==n*n-1)
            return 1;
            for(int z=0;z<8;z++){
                int x1=x[z]+i;
                int y1=j+y[z];
                if(x1>=0 && y1>=0 && x1<n && y1<n && vis[num+1]==0 && num+1==grid[x1][y1]){
                    q.push({num+1,{x1,y1}});
                    vis[num+1]=1;
                }
            }
        }
        return 0;
    }
    bool checkValidGrid(vector<vector<int>>& grid) {
        if(grid[0][0]!=0)
        return 0;
        return bfs(grid);
    }
};