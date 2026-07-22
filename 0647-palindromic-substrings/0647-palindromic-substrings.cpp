class Solution {
public:
    int countSubstrings(string s) {
        int n=s.size();
        int c=0;
        vector<vector<int>>arr(n,vector<int>(n,0));
        for(int j=0;j<n;j++){
            for(int i=0;i+j<n;i++){
                if(j==0)
                arr[i][i+j]=1;
                else if(j==1 && s[i]==s[i+j])
                arr[i][i+j]=2;
                else if(s[i]==s[i+j] && arr[i+1][i+j-1]!=0){
                    arr[i][i+j]=2+arr[i+1][j+i-1];
                }
                if(arr[i][i+j]!=0)
                c++;
            }
        }
        return c;
    }
};