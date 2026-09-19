class Solution {
public:
    int equalSubstring(string s, string t, int maxCost) {
        int len=0,cost=0;
        int l=0;
        for(int r=0;r<s.size();r++){
            cost+=abs(s[r]-t[r]);
            while(cost>maxCost){
                cost-=abs(s[l]-t[l]);
                l++;
            }
            len=max(len,r-l+1);
        }
        return len;
    }
};