class Solution {
public:
    int maximumLengthSubstring(string s) {
        unordered_map<char,int>a;
        int ma=0;
        int l=0;
        for(int i=0;i<s.size();i++){
            a[s[i]]++;
            while(a[s[i]]>2){
                a[s[l]]--;
                l++;
            }
            ma=max(ma,i-l+1);
        }
        return ma;
    }
};