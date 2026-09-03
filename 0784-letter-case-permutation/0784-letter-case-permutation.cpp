class Solution {
public:
    void recur(int i,string& s,string temp,vector<string>&ans){
        if(i==s.size()){
            return;
        }
        if((s[i]>=65 && s[i]<=90) || (s[i]>=97 && s[i]<=122)){
            temp[i]=temp[i]^32;
            ans.push_back(temp);
            recur(i+1,s,temp,ans);
            temp[i]=temp[i]^32;
        }
        recur(i+1,s,temp,ans);
    }
    vector<string> letterCasePermutation(string s) {
        vector<string>ans;
        string temp=s;
        recur(0,s,temp,ans);
        ans.push_back(s);
        return ans;
    }
};