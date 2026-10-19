class Solution {
public:
    vector<int> lastVisitedCell(vector<vector<char>>& grid) {
        if(grid[0][0]=='U')
        return {0,0};
        queue<pair<int,int>>q;
        if(grid[0][0]=='D'){
            q.push({1,0});
        }
        else if(grid[0][0]=='L')
            return {0,0};
        else if(grid[0][0]=='R')
            q.push({0,1});
        grid[0][0]='Q';
        int l=0,m=0;
        while(!q.empty()){
            int a=q.front().first;
            int b=q.front().second;
            q.pop();
            if(a>=grid.size() || b>=grid[0].size())
            return {0,0};
            if(grid[a][b]=='U' && a-1>=0 && grid[a-1][b]!='Q'){
                q.push({a-1,b});
            }
            else if(grid[a][b]=='D' && a+1<grid.size() && grid[a+1][b]!='Q'){
                q.push({a+1,b});
            }
            else if(grid[a][b]=='R' && b+1<grid[0].size() && grid[a][b+1]!='Q'){
                q.push({a,b+1});
            }
            else if(grid[a][b]=='L' && b-1>=0 && grid[a][b-1]!='Q'){
                q.push({a,b-1});
            }
            else 
                return {a,b};
            grid[a][b]='Q';
        }
        return {0,0};
    }
};