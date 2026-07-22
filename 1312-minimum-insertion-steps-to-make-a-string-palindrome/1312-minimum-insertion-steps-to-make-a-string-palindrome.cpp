class Solution {
public:
    int minInsertions(string s) {
        int n=s.size();
        vector<vector<int>>arr(n+1,vector<int>(n+1,0));
        string s1=s;
        reverse(s.begin(),s.end());
        for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++){
                if(s1[i-1]==s[j-1])
                    arr[i][j]=1+arr[i-1][j-1];
                else
                    arr[i][j]=max(arr[i-1][j],arr[i][j-1]);
            }
        }
        return s.size()-arr[n][n];
    }
};