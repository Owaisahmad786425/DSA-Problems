class Solution {
    int n;
    const int M=1000000007;
    //binary exponentiation
    int findpower(long long a,long long b){
     int res=1;
     while(b>0){
       if(b%2==1){
        res=(res*a)%M;
        b/=2;
        a=(a*a)%M;
        continue;
       }
       b/=2;
       a=(a*a)%M;
     }
     return res%M;
    }

   int fun(int digit,int even_digit_count,int sum,int target,vector<long long> &fact,vector<long long> &fermat_fact,vector<int> &freq,long long &total_perm_possible){
if(digit==10){
    if(sum==target && even_digit_count==((n+1)/2)){
        return total_perm_possible;
    }
    return 0;
}
    long long ways=0;
    for(int count=0;count<=min(freq[digit], (n+1)/2-even_digit_count);count++){
        int even_parity=count;
        int odd_parity=freq[digit]-count;

        long long digit_diff=(fermat_fact[even_parity]*fermat_fact[odd_parity])%M;
         long long val=fun(digit+1,even_digit_count+even_parity,sum+digit*count,target,fact,fermat_fact,freq,total_perm_possible);

         ways=(ways+(val*digit_diff))%M;
    }
    return ways;
   }


public:
    int countBalancedPermutations(string num) {
        n=num.size();
        vector<int> freq(10,0);
        int total_sum=0;
        for(int i=0;i<n;i++){
            freq[num[i]-'0']++;
            total_sum+=num[i]-'0';
        }
        if(total_sum%2!=0){
            return 0;
        }
        int target=total_sum/2;
        vector<long long> fact(n+1);
        fact[0]=1;
        fact[1]=1;
        for(int i=2;i<=n;i++){
            fact[i]=(fact[i-1]*i)%M;
        }
        //new concept
        vector<long long> fermat_fact(n+1,1);
        for(int i=0;i<=n;i++){
            fermat_fact[i]=findpower(fact[i],M-2)%M;
        }
      long long total_perm_possible=(1LL*fact[(n+1)/2]*fact[n/2])%M;
      int digit=0;
      int even_digit_count=0;
      int sum=0;
        return fun(digit,even_digit_count,sum,target,fact,fermat_fact,freq,total_perm_possible);

    }
};