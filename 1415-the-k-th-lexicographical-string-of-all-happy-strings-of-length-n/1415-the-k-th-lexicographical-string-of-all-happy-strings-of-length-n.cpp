class Solution {
public:
    void combination(vector<char>&ans1,int n,vector<string>&ans2,string temp,char c){
        if(temp.size()==n )
        {
            ans2.push_back(temp);
            return;
        }
        for(int j=0;j<ans1.size();j++){
            char p=ans1[j];
            if(p!=c){
                combination(ans1,n,ans2,temp+ans1[j],ans1[j]);
            }
        }
    }
    string getHappyString(int n, int k) {
        vector<char>ans1;
        ans1.push_back('a');
        ans1.push_back('b');
        ans1.push_back('c');
        vector<string>ans2;
        string temp="";
        char c='0';
        combination(ans1,n,ans2,temp,c);
        sort(ans2.begin(),ans2.end());
        if(ans2.size()<k)
        return "";
        return ans2[k-1];
    }
};