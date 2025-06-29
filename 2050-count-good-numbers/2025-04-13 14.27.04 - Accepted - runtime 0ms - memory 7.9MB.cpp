class Solution {
      long long modpow(long long base, long long exp, long long mod) {
        long long result = 1;
        base %= mod;
        while (exp > 0) {
            if (exp % 2 == 1)
                result = (result * base) % mod;
            base = (base * base) % mod;
            exp /= 2;
        }
        return result;
    }
public:
    int countGoodNumbers(long long n) {
        int MOD=1000000000+7;
        long long even_indices=(n+1)/2;
        long long odd_indices=n-even_indices;
        long long possibility_even_indices=modpow(5,even_indices,MOD);
        long long possibility_odd_indices=modpow(4,odd_indices,MOD);
       long long res=(possibility_even_indices*possibility_odd_indices);
       return (res%MOD);
    }
};