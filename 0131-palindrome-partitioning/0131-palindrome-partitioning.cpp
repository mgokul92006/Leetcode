class Solution {
public:
    bool pali(int j,string& s,int i){
        while(i<j){
            if(s[i]!=s[j])
                return 0;
            i++;
            j--;
        }
        return 1;
    }
    void recur(string& s,int i,vector<string>&temp,vector<vector<string>>&ans){
        if(i==s.size()){
        ans.push_back(temp);
        return;
        }
        for(int j=i;j<s.size();j++){
            if(pali(j,s,i)){
                string sub=s.substr(i,j-i+1);
                temp.push_back(sub);
                recur(s,j+1,temp,ans);
                temp.pop_back();
            }
        }
    }
    vector<vector<string>> partition(string s) {
        vector<string>temp;
        vector<vector<string>>ans;
        recur(s,0,temp,ans);
        return ans;
    }
};