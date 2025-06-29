class Solution {
public:
    int strStr(string haystack, string needle) {
        int n=haystack.size();
        int m=needle.size();
        vector<int> LPS(m);
        LPS[0]=0;
        int len=0;
        for(int i=1;i<m;i++){
          if(needle[i]==needle[len]){
            len++;
            LPS[i]=len;
            continue;
              }
        while(len>0 && needle[i]!=needle[len]){
            len--;

        }
        LPS[i]=len;

        }
        int j=0;
   for(int i=0;i<n;i++){
     if(j>=m){
        return (i-m);
    }
    else if(haystack[i]==needle[j]){
        j++;
        continue;
    }
    if(j>0 && haystack[i]!=needle[j]){
        j=LPS[j-1];
    }
   }
      return -1;   
    }
};