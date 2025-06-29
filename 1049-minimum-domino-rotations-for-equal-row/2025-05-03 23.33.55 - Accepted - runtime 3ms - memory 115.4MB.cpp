class Solution {
public:
    int minDominoRotations(vector<int>& tops, vector<int>& bottoms) {
        int n=tops.size();
        int res=1e9;
        for(int i=1;i<=6;i++){
            int op1=0,j=0;
            int op2=0;
             while(j<n){
                if(tops[j]!=i && bottoms[j]!=i){
                 break;
                }
                if(tops[j]==i && bottoms[j]!=i){
                    op2++;
                }
                else if(tops[j]!=i && bottoms[j]==i){
                    op1++;
                }
            j++;
    
             }
             if(j<n){
                continue;
             }
      res=min(res,min(op1,op2));
        }

        if(res==1e9){
            return -1;
        }
        return res;


            }
};