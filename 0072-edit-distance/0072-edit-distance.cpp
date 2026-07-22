class Solution {
public:
    int minDistance(string word1, string word2) {
        int n=word1.size(),m=word2.size();
        int arr[n+1][m+1];
        for(int i=0;i<=n;i++){
            for(int j=0;j<=m;j++){
                if(i==0){
                    arr[i][j]=j;
                }
                else if(j==0)
                    arr[i][j]=i;
                else if(word1[i-1]==word2[j-1]){
                    arr[i][j]=arr[i-1][j-1];
                }
                else{
                    arr[i][j]=min({arr[i-1][j-1],arr[i-1][j],arr[i][j-1]})+1;
                }
            }
        }
        return arr[n][m];
    }
};