class Solution {
public:
    int x[4]={1,-1,0,0};
    int y[4]={0,0,1,-1};
    int path(set<vector<vector<int>>>&a,vector<vector<int>>& board){
        vector<vector<int>>ans={{1,2,3},{4,5,0}};
        if(board==ans)
        return 0;
        queue<tuple<vector<vector<int>>,int>>q;
        q.push({board,0});
        while(!q.empty()){
            auto [b,st]=q.front();
            q.pop();
            if(b==ans)
            return st;
            int l,m;
            for(int i=0;i<2;i++){
                for(int j=0;j<3;j++){
                    if(b[i][j]==0){
                        l=i;
                        m=j;
                        break;
                    }
                }
            }
            for(int z=0;z<4;z++){
                int x1=l+x[z];
                int y1=m+y[z];
                if(x1>=0 && y1>=0 && x1<2 && y1<3){
                    vector<vector<int>>temp=b;
                    swap(temp[x1][y1],temp[l][m]);
                    if(a.find(temp)==a.end()){
                    q.push({temp,st+1});
                    a.insert(temp);
                    }
                }
            }
        }
        return -1;
    }
    int slidingPuzzle(vector<vector<int>>& board) {
        set<vector<vector<int>>>a;
        a.insert(board);
        return path(a,board);
    }
};