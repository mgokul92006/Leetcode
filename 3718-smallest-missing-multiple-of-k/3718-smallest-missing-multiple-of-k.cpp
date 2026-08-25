class Solution {
public:
    int missingMultiple(vector<int>& nums, int k) {
        map<int,int>a;
        for(int i=0;i<nums.size();i++){
            a[nums[i]]++;
        }
        int j=2;
        int temp=k;
        while(1){
            if(a.find(temp)!=a.end()){
                temp=j*k;
                j++;
            }
            else
            return temp;
        }
    }
};