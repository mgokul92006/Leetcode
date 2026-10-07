class Solution {
public:
    unordered_set<string>s1;
    int maxLen=0;
    void recur(string& s,int i,string& temp,int bal){
        if(bal<0)
        return;
        if(s.size()==i){
            if(bal==0 && maxLen<temp.size()){
                maxLen=temp.size();
                s1.clear();
                s1.insert(temp);
            }
            if(bal==0 && temp.size()==maxLen)
                s1.insert(temp);
            return;
        }
        if(s[i]!='(' && s[i]!=')'){
            temp.push_back(s[i]);
            recur(s,i+1,temp,bal);
            temp.pop_back();
        }
        else{
        temp.push_back(s[i]);
        recur(s,i+1,temp,s[i]=='('?bal+1:bal-1);
        temp.pop_back();
        recur(s,i+1,temp,bal);
        }
    }
    vector<string> removeInvalidParentheses(string s) {
        string temp="";
        recur(s,0,temp,0);
        vector<string>ans;
        for(auto i:s1){
            if(i.size()==maxLen)
                ans.push_back(i);
        }
        return ans;
    }
};