class Solution {
public:
    string evaluate(string s, vector<vector<string>>& knowledge) {
        string ans="";
        map<string,string>mp;
        for(int i=0;i<knowledge.size();i++){
            mp[knowledge[i][0]]=knowledge[i][1];
        }
        for(int i=0;i<s.size();){
            if(s[i]=='('){
                string key1="";
                i++;
                while(s[i]!=')'){
                    key1+=s[i];
                    i++;
                }
                i++;
                if(mp.find(key1)!=mp.end()){
                    ans+=mp[key1];
                }
                else
                    ans=ans+'?';
            }
            else{
                ans+=s[i];
                i++;
            }
        }
        return ans;
    }
};