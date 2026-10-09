class Solution {
public:
    int minInsertions(string s) {
        int close=0,ans=0;
        for(int i=0;i<s.size();i++){
            if(s[i]=='('){
                if(close%2==1){
                    ans++;
                    close--;
                }
                close+=2;
            }
            else{
                close--;
                if(close==-1){
                    ans+=1;
                    close+=2;
                }
            }
        }
        return ans+close;
    }
};