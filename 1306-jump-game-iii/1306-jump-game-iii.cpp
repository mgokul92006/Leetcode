class Solution {
public:
    bool canReach(vector<int>& arr, int start) {
        vector<int>vis(arr.size(),0);
        vis[start]=1;
        queue<int>q;
        q.push(start);
        while(!q.empty()){
            int i=q.front();
            q.pop();
            if(arr[i]==0)
            return 1;
            int newIndex1=i+arr[i],newIndex2=i-arr[i];
            if(newIndex1<arr.size() && vis[newIndex1]==0){
                q.push(newIndex1);
                vis[newIndex1]=1;
            }
            if(newIndex2>=0 && vis[newIndex2]==0){
                q.push(newIndex2);
                vis[newIndex2]=1;
            }
        }
        return 0;
    }
};