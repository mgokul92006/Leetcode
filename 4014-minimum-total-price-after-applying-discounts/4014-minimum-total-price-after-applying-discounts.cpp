class Solution {
public:
    double minPrice(vector<int>& prices, vector<int>& discounts) {
        sort(prices.begin(),prices.end());
        sort(discounts.begin(),discounts.end());
        double sum=0;
        int j=discounts.size()-1;
        for(int i=prices.size()-1;i>=0;i--){
            if(j>=0){
            sum=sum+(prices[i]*1.0*((100-discounts[j])/100.0));
            j--;
            }
            else
                sum=sum+prices[i];
        }
        return sum;
    }
};