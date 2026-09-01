class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        map<char,int>mp;
        int l=0,maxi=0;
        for(int r=0;r<s.size();r++){
            mp[s[r]]++;
            while(mp[s[r]]>1){
                mp[s[l]]--;
                if(mp[s[l]]==0)
                mp.erase(s[l]);
                l++;
            }
            maxi=max(maxi,r-l+1);
        }
        return maxi;
    }
};