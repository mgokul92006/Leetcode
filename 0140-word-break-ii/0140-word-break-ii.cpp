class Solution {
public:
    void recur(string& s,unordered_set<string>&con,string temp,int i,vector<string>&ans){
        if(i>=s.size()){
            temp.pop_back();
            ans.push_back(temp);
        }
        string temp1="";
        for(int j=i;j<s.size();j++){
            temp1=temp1+s[j];
            if(con.find(temp1)!=con.end()){
                recur(s,con,temp+temp1+" ",j+1,ans);
            }
        }
    }
    vector<string> wordBreak(string s, vector<string>& wordDict) {
        vector<string>ans;
        unordered_set<string>con(wordDict.begin(),wordDict.end());
        string temp="";
        recur(s,con,temp,0,ans);
        return ans;
    }
};