class Solution {
public:
    int maxDepth(string s) {
        int maxi=0;
        int in=0;
        for(int i=0;i<s.size();i++){
            if(s[i]=='(')
                in++;
            else if(s[i]==')')
                in--;
            maxi=max(maxi,in);
        }
        return maxi;
    }
};