class Solution {
public:
    long long shiftDistance(string s, string t, vector<int>& nextCost, vector<int>& previousCost) {
        long long res=0;
        int n=s.size();
        for(int i=0;i<n;i++){
            long long index=s[i]-'a';
            //for next
          long long j=index;
          long long sum1=0;
          long long sum2=0;
          while(j!=t[i]-'a'){
            sum1+=nextCost[j];
            j++;
            if(j>25){
            j=0;
            }
          }
          //for prev cost
          while(index!=t[i]-'a'){
            sum2+=previousCost[index];
            index--;
            if(index<0){
                index=25;
            }
          }
          long long  mini=min(sum1,sum2);
          res+=mini;

        }
return res;

    }
};