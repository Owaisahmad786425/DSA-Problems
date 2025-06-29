class Solution {
public:
    int numberOfAlternatingGroups(vector<int>& colors, int k) {
       int index=1;
       int n=colors.size();
       int len=1;
       int res=0;
       int lastvis=colors[0];
       for(int i=0;i<(n+k-2);i++){
        if(colors[index]==lastvis){
            len=1;
            lastvis=colors[index];
            index=(index+1)%n;
            continue;
        }
        len++;
        if(len>=k){
            res++;
        }
        lastvis=colors[index];
        index=(index+1)%n;
      
       }
       return res;
    }
};