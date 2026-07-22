class Solution {
public:
    bool isMatch(string s, string p) {
        int n=s.size(),m=p.size();
        vector<vector<bool>>  arr(m+1,vector<bool>(n+1,0));
        arr[0][0]=1;
        for(int i = 1 ; i <= m ;i++ ) 
            if( p[i-1] == '*' )
                arr[i][0] = arr[i-1][0];
        for(int i=1;i<=m;i++){
            for(int j=1;j<=n;j++){
                if(s[j-1]==p[i-1] || p[i-1]=='?' )
                    arr[i][j]=arr[i-1][j-1];
                else if(p[i-1]=='*')
                    arr[i][j]=(arr[i-1][j] || arr[i][j-1]);
            }
        }
        return arr[m][n];
    }
};