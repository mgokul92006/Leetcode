class NumArray {
public:
    vector<int>seg;
    int size=0;
    int queri(int i,int l1,int r1,int l,int r){
        if(r1<l || r<l1)
        return 0;
        if(l1>=l && r1<=r)
        return seg[i];
        int m=(r1-l1)/2+l1;
        int left=queri(2*i+1,l1,m,l,r);
        int right=queri(2*i+2,m+1,r1,l,r);
        return left+right;
    }
    void upDate(int i,int pos,int val,int l1,int r1){
        if(l1==r1){
            seg[i]=val;
            return;
        }
        int m=(r1-l1)/2+l1;
        if(pos<=m)
            upDate(i*2+1,pos,val,l1,m);
        else
            upDate(i*2+2,pos,val,m+1,r1);
        seg[i]=seg[i*2+1]+seg[i*2+2];
    }
    void build(int i,vector<int>&nums,int l1,int r1){
        if(l1==r1){
            seg[i]=nums[l1];
            return;
        }
        int m=(r1-l1)/2+l1;
        build(2*i+1,nums,l1,m);
        build(2*i+2,nums,m+1,r1);
        seg[i]=seg[i*2+1]+seg[i*2+2];
    }
    NumArray(vector<int>& nums) {
        int n=nums.size();
        size=n;
        int c=1;
        while(n){
            n=n/2;
            c++;
        }
        seg.resize(pow(2,c)-1,0);
        build(0,nums,0,nums.size()-1);
    }
    
    void update(int index, int val) {
        upDate(0,index,val,0,size-1);
    }
    
    int sumRange(int left, int right) {
        int sum=queri(0,0,size-1,left,right);
        return sum;
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * obj->update(index,val);
 * int param_2 = obj->sumRange(left,right);
 */