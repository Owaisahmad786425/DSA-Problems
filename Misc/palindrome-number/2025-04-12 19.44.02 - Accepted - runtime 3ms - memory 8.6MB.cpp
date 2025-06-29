class Solution {
public:
    bool isPalindrome(int x) {
        int temp=x;
        long long res=0;
        while(temp>0){
            int t=temp%10;
            res=(res*10)+t;
            temp=temp/10;
        }
        if(res==x){
            return true;
        }
        return false;
    }
};