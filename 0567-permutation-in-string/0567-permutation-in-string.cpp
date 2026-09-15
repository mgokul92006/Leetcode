class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        int size=s1.size();
        unordered_map<char,int>mp;
        for(int i=0;i<size;i++){
            mp[s1[i]]++;
        }
        unordered_map<char,int>mp1;
        int size2=s2.size();
        for(int i=0;i<min(size,size2);i++){
            mp1[s2[i]]++;
        }
        if(mp==mp1)
        return 1;
        for(int i=size;i<s2.size();i++){
            mp1[s2[i-size]]--;
            mp1[s2[i]]++;
            if(mp1[s2[i-size]]==0)
                mp1.erase(s2[i-size]);
            if(mp==mp1)
            return 1;
        }
        return 0;
    }
};