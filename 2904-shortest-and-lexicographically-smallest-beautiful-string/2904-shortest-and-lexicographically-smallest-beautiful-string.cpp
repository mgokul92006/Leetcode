class Solution {
public:
    string shortestBeautifulSubstring(string s, int k) {
        int l=0,r=0;
        unordered_map<char,int>a;
        vector<string>ans;
        while(r<s.size()){
            if(s[r]=='1')
            a[s[r]]++;
            while(a['1']==k){
                string p="";
                for(int i=l;i<=r;i++)
                    p=p+s[i];
                ans.push_back(p);
                if(s[l]=='1')
                a[s[l]]--;
                l++;
            }
            r++;
        }
        for(int i=0;i<ans.size();i++)
            cout<<ans[i]<<" ";
        int small=INT_MAX;
        string ans1="";
        for(int i=0;i<ans.size();i++)
        {
            if(small>ans[i].size()){
                small=ans[i].size();
            }
        }
        set<string>q;
        for(auto i:ans){
            if(i.size()==small)
                q.insert(i);
        }
        for(auto i:q)
        return i;
        return ans1;
    }
};