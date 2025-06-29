class Solution {
public:
    bool canAliceWin(int n) {
int aliceturn=10;
        int bobturn=9;
        bool flag;
        while(n>0){
            if(n>=aliceturn){
                n=n-aliceturn;
                aliceturn=aliceturn-2;
            }
            else{
                flag=false;
                break;
            }
            if(n>=bobturn){
                n=n-bobturn;
                bobturn=bobturn-2;
            }
            else{
                flag=true;
                break;
            }

        }
        return flag;
    }
};