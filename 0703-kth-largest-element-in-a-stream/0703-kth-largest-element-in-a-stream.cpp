class KthLargest {
public:
    priority_queue<int,vector<int>,greater<int>>q;
    int v;
    KthLargest(int k, vector<int>& nums) {
        v=k;
        for(auto i:nums){
            if(v>q.size())
            q.push(i);
            else if(i>q.top()){
                q.push(i);
                q.pop();
            }
        }
    }
    
    int add(int val) {
        if(v>q.size())
        q.push(val);
        else if(val>q.top()){
            q.push(val);
            q.pop();
        }
        return q.top();
    }
};

/**
 * Your KthLargest object will be instantiated and called as such:
 * KthLargest* obj = new KthLargest(k, nums);
 * int param_1 = obj->add(val);
 */