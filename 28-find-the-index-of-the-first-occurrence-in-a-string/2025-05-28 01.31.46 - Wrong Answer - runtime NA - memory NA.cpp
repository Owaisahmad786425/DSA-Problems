class Solution {
public:
    int strStr(string haystack, string needle) {
        int n=haystack.size();
        int m=needle.size();
        vector<int> LPS(m);
        LPS[0]=0;
        int len=0;
        for(int i=1;i<m;i++){
        while(len>0 && needle[i]!=needle[len]){
            len--;

        }
            if(needle[i]==needle[len]){
            len++;
            LPS[i]=len;
            continue;
              }

        }
        int j=0;
        int i=0;
    while(i<n){
     if(j>=m){
        return (i-m);
    }
    else if(haystack[i]==needle[j]){
        j++;
        i++;
        continue;
    }
    if(haystack[i]!=needle[j]){
       if(j>0){
        j=LPS[j-1];
       }
       else{
        i++;
       }
    }
   }
   if(j>=m){
    return i-m;
   }
      return -1;   
    }
};