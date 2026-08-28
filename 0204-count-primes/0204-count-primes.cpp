vector<int> arr(5000007 , 1 );
int flag = 0;
void precompute(){
    if( flag ) return ;
    flag = 1;
    arr[0]=0;
    arr[1]=0;
    int n = 5000000;
    for(int i=2;i*i <= n;i++){
        if(arr[i]==1){
            for(int j=i+i;j<=n;j=j+i){
                if(j%i==0){
                    arr[j]=0;
                }
            }
        }
    }
}
class Solution {
public:
    int function(int n){
        if(n==0)
            return 0;
        precompute();
        int c=0;
        for(int i=2;i<n;i++){
            if(arr[i]==1)
                c++;
        }
        return c;
    }
    int countPrimes(int n) {
        return function(n);
    }
};