class Solution {
public:
    int dpCalculate(string& a,int i,int tight,int lz,int change){
        if(a.size()==i)
        return change==1?1:0;
        int ans=0;
        int ub=(tight==1)?a[i]-'0':9;
        for(int j=0;j<=ub;j++){
            if(j==3 || j==4 || j==7)
                continue;
            if(j==0 && lz)
                ans=ans+dpCalculate(a,i+1,(tight && j==ub),lz,change);
            else{
            int flag=0;
            if(j==2 || j==5 || j==6 || j==9)
                flag=1;
            ans=ans+dpCalculate(a,i+1,(tight && j==ub),lz && j==0,flag || change);
            }
        }
        return ans;
    }
    int rotatedDigits(int n) {
        string ans=to_string(n);
        return dpCalculate(ans,0,1,1,0);
    }
};