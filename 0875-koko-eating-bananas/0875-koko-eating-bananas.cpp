class Solution {
public:
    bool check(int m,vector<int>&piles,int h){
        long long c=0;
        int sum=0;
        for(int i=0;i<piles.size();i++){
            c=c+(piles[i]/m);
            if(piles[i]%m!=0)
            c=c+1;
        }
        return c<=h;
    }
    int minEatingSpeed(vector<int>& piles, int h) {
        int low=1;
        int ans=0;
        int high=*max_element(piles.begin(), piles.end());
        while(low<=high){
            long long m=low+(high-low)/2;
            if(check(m,piles,h)){
                ans=m;
                high=m-1;
            }
            else
                low=m+1;
        }
        return ans;
    }
};