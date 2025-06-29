class Solution {
public:
    bool isBalanced(string num) {
    int n=num.size();
        int sum1=0;
        int sum2=0;
        for(int i=0;i<n;i++){
            if(i%2==0){
                sum1+=num[i]-'0';
            }
            else{
                sum2+=num[i]-'0';
            }
        }
        if(sum1==sum2){
            return true;
        }
        return false;
    }
};