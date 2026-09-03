class Solution {
public:
    void recur(int i,string& digits,unordered_map<int,string>&mp,string& temp,vector<string>&ans){
        if(i==digits.size()){
            if(temp.size()==digits.size())
            ans.push_back(temp);
            return;
        }
        for(int j=i;j<digits.size();j++){
            for(char c:mp[digits[j]-'0']){
                temp=temp+c;
                recur(j+1,digits,mp,temp,ans);
                temp.pop_back();
            }
        }
    }
    vector<string> letterCombinations(string digits) {
        unordered_map<int,string>mp;
        mp[2]="abc";
        mp[3]="def";
        mp[4]="ghi";
        mp[5]="jkl";
        mp[6]="mno";
        mp[7]="pqrs";
        mp[8]="tuv";
        mp[9]="wxyz";
        string temp="";
        vector<string>ans;
        recur(0,digits,mp,temp,ans);
        return ans;
    }
};