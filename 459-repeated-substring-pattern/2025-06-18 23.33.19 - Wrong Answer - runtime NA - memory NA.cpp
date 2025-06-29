class Solution {
public:
    bool repeatedSubstringPattern(string s) {
      int n =s.size();
      if(n==1){
        return false;
      }
      vector<int> lps(n);
      lps[0]=0;
      bool flag=0;
      int starting_index=-1;
      for(int i=1;i<n;i++){
        int count=lps[i-1];
        while(count>0 && s[i]!=s[count]){
            count--;
        }
        if(s[i]==s[count]){
            if(count==0 &&!flag){
                starting_index=i;
                flag=1;
            }
            lps[i]=count+1;
            continue;
        }
        if(count==0){
            lps[i]=0;
        }
      }  
if(n%2!=0){
    for(int i=1;i<n;i++){
        if(lps[i]!=lps[i-1]+1){
            return false;
        }
    }
}
for(int i=starting_index;i<n;i++){
   if(lps[i-1]>=lps[i]){
    return false;
   }
}
return true;
    }
};