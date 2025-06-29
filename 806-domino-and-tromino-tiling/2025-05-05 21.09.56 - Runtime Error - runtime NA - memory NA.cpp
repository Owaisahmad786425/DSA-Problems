class Solution {
public:
    int numTilings(int n) {
        if(n==1 ||n==0){
            return 1;
        }
        else if(n==2){
            return 2;
       }
       return 2*numTilings(n-1)+numTilings(n-3);
    }
};