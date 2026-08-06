class Solution {
public:
    int smallestNumber(int n, int t) {
        while(n){
            int i=n;
            int sum=1;
            while(i){
                sum=sum*(i%10);
                i=i/10;
            }
            if(sum%t==0)
            return n;
            n++;
        }
        return 0;
    }
};