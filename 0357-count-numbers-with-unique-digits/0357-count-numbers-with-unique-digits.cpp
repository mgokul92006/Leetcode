class Solution {
public:
    int dpCalculate(string& a,int n,int i,int tight,int lz,int rep,int mask){
        if(a.size()==i)
            return rep>0?0:1;
        int ans=0;
        int ub=(tight==1)?a[i]-'0':9;
        for(int j=0;j<=ub;j++){
            if(j==0 && lz)
                ans=ans+dpCalculate(a,n,i+1,tight && j==ub,lz,rep,mask);
            else{
                int in=1 & mask>>j;
                ans=ans+dpCalculate(a,n,i+1,tight && j==ub,lz && j==0,rep || in,mask | 1<<j);
            }
        }
        return ans;
    }
    int countNumbersWithUniqueDigits(int n) {
        string ans="";
        for(int i=1;i<=n;i++)
            ans=ans+'9';
        return dpCalculate(ans,n+1,0,1,1,0,0);        
    }
};