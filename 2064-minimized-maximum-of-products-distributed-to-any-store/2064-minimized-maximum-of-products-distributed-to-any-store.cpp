class Solution {
public:
    bool check(int m,vector<int>&arr,int n){
        int c=0;
        for(auto i:arr){
            if(i%m==0)
                c=c+i/m;
            else
                c=c+i/m+1;
        }
        return c<=n;
    }
    int minimizedMaximum(int n, vector<int>& quantities) {
        int l=1,h=*max_element(quantities.begin(),quantities.end());
        int ans=0;
        while(l<=h){
            int m=(l+h)/2;
            if(check(m,quantities,n)){
                ans=m;
                h=m-1;
            }
            else
                l=m+1;
        }
        return ans;
    }
};