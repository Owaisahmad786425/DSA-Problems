class Solution {
public:
    int numberOfArrays(vector<int>& differences, int lower, int upper) {
        int mini=0;
        int maxi=0;
        int n=differences.size();
       int  curr=0;
        for(int i=0;i<n;i++){
            curr+=differences[i];
            mini=min(curr,mini);
            maxi=max(curr,maxi);
            if((upper-maxi)-(lower-mini)+1<=0){
                return 0;
            }
        }
        return ((upper-maxi)-(lower-mini)+1);
    }
};