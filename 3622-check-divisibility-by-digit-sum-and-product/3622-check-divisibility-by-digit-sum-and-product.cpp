class Solution {
public:
    bool checkDivisibility(int n) {
        int f=n;
        int sum=0;
        int max=1;
        while(n>0)
        {
            int d=n%10;
            sum=sum+d;
            max=max*d;
            n=n/10;
        }
        if(f%(sum+max)==0)
            return true;
        return false;
    }
};