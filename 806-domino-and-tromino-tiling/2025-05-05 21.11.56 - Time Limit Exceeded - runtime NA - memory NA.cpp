class Solution {
    const int MOD=1000000007;
public:
    int numTilings(int n) {
        if(n==1 ||n==0){
            return 1;
        }
        else if(n==2){
            return 2;
       }
       return (2*numTilings(n-1)%MOD+numTilings(n-3)%MOD)%MOD;
    }
};