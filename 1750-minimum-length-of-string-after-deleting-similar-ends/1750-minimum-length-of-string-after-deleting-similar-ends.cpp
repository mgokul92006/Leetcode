class Solution {
public:
    int minimumLength(string s) {
        int mini=1e9;
        int i=0,j=s.size()-1;
        char c;
        while(i<j){
            if(s[i]==s[j]){
               c=s[i];
               i++;
               j--;
               while(1 && i<s.size()){
                if(c==s[i])
                i++;
                else
                break;
               }
               while(1 && j>=0){
                if(c==s[j])
                j--;
                else
                break;
               }
               mini=min(mini,j-i+1);
            }
            else
            break;
        }
        if(mini<0)
        return 0;
        return mini==1e9?s.size():mini;
    }
};