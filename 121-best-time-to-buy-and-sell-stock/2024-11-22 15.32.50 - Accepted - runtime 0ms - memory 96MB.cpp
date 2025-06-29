class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int el=prices[0];
        int maxi=0;
        for(int i=0;i<prices.size();i++){
 if(prices[i]>el){
    int profit=prices[i]-el;
    maxi=max(maxi,profit);
 }
  else if(prices[i]<el){
    el=prices[i];
  }      }
  return maxi;
    }
};