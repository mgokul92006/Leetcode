class Solution {
public:
    int dpCalculate(int n,vector<char>&arr,int i){
        if(n==0)
        return 1;
        int ans=0;
        for(int j=i;j<arr.size();j++){
            ans=ans+dpCalculate(n-1,arr,j);
        }
        return ans;
    }
    int countVowelStrings(int n) {
        vector<char>arr={'a','e','i','o','u'};
        return dpCalculate(n,arr,0);
    }
};