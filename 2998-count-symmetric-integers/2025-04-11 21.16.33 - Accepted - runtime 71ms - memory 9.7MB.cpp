class Solution {
public:
    int countSymmetricIntegers(int low, int high) {
        int res=0;
       for(int i=low;i<=high;i++){
        string convert=to_string(i);
       int len=convert.length();
       if(len%2!=0){
        continue;
       }
    int len2=len/2;
    int sum1=0;
    for(int j=0;j<len2;j++){
   sum1+=convert[j]-'0';
    }
    int sum2=0;
  for(int j=len2;j<len;j++){
    sum2+=convert[j]-'0';
  }
  if(sum1==sum2){
    res++;
  }
       }
       return res;    }
};