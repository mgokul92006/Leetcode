class Solution {
public:
    vector<int> maxDepthAfterSplit(string seq) {
        int c=0,maxi=0;
        for(auto i:seq){
            if(i=='(')
                c++;
            else if(i==')')
                c--;
            maxi=max(c,maxi);
        }
        int a1=0,b1=0;
        if(maxi%2==0){
            a1=maxi/2;
            b1=a1;
        }
        else{
            a1=maxi/2;
            b1=maxi-a1;
        }
        stack<pair<char,int>>st;
        vector<int>ans(seq.size());
        for(int i=0;i<seq.size();i++){
            if(seq[i]=='('){
                if(a1!=0){
                    a1--;
                    st.push({'(',0});
                    ans[i]=0;
                }
                else if(b1!=0){
                    b1--;
                    st.push({'(',1});
                    ans[i]=1;
                }
            }
            else if(seq[i]==')' ){
                if(st.top().first=='(' && st.top().second==0){
                    ans[i]=0;
                    st.pop();
                    a1++;
                }
                else{
                    ans[i]=1;
                    st.pop();
                    b1++;
                }
            }
        }
        return ans;
    }
};