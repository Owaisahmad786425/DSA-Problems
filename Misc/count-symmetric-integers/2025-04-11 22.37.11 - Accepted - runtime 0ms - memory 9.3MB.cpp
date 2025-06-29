class Solution {
public:
    int countSymmetricIntegers(int low, int high) {
        int res=0;
        for(int i=low;i<=high;i++){
            if(i>=10 && i<=99 &&i%11==0){
                res++;
            }
            else if(i>=1000 && i<=9999){
                int sum1=0;
                int sum2=0;
                sum1+=(i/1000);
                sum1+=((i/100)%10);
              sum2+=((i/10)%10);
              sum2+=(i%10);
              if(sum1==sum2){
                res++;
              }
            }
        }
        return res;
    }
};