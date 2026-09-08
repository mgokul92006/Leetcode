class Solution {
public:
    double champagneTower(int poured, int query_row, int query_glass) {
        vector<vector<double>>ans(query_row+1,vector<double>(query_row+1,0.0));
        ans[0][0]=poured;
        for(int i=0;i<query_row;i++){
            for(int j=0;j<=query_row;j++){
                double balance=(ans[i][j]-1.0)*0.5;
                if(balance>0.0){
                    ans[i+1][j]=ans[i+1][j]+balance;
                    ans[i+1][j+1]=ans[i+1][j+1]+balance;
                }
            }
        }
        return min(1.0,ans[query_row][query_glass]);
    }
};