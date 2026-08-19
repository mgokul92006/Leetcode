class Solution {
public:
    bool check(string s){
        stack<char>a;
        if(s.size()==1)
        return false;
        for(int i=0;i<s.size();i++){
            if((s[i]=='(')||(s[i]=='[')||(s[i]=='{')){
                a.push(s[i]);
            }
            else if(s[i]==')'){
                if(a.empty())
                return false;
                else if(a.top()=='(')
                a.pop();
                else
                a.push(s[i]);
            }
            else if(s[i]==']'){
                if(a.empty())
                return false;
                else if(a.top()=='[')
                a.pop();
                else
                a.push(s[i]);
            }
            else if(s[i]=='}'){
                if(a.empty())
                return false;
                else if(a.top()=='{')
                a.pop();
                else
                a.push(s[i]);
            }
        }
        if(a.empty()){
            return true;
        }
        else
            return false;
    }
    void gene(int n,int i,string s,vector<string>&ans){
        if(n*2==i){
            if(check(s)){
                ans.push_back(s);
            }
            return;
        }
        s=s+'(';
        gene(n,i+1,s,ans);
        s.pop_back();
        s=s+')';
        gene(n,i+1,s,ans);
    }
    vector<string> generateParenthesis(int n) {
        vector<string>ans;
        string s="(";
        gene(n,1,s,ans);
        return ans;
    }
};