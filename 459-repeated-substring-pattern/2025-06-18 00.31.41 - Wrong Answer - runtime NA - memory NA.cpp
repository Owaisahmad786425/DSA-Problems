class Solution {
public:
    bool repeatedSubstringPattern(string s) {
     string prefix="";
     string suffix="";
     int count=0;
     int n=s.size();
     char var=' ';
     bool flag=0;
     for(int i=0;i<n;i++){
     if(var!=s[i]){
        count++;
        var=s[i];
     }
     if(count>1){
        flag=1;
        break;
     }
     }
   
      if(n%2!=0 &&!flag){
       return true;
      }
     int index=n/2;
     for(int i=0;i<index;i++){
        prefix+=s[i];
     }
     for(int i=index;i<n;i++){
        suffix+=s[i];
     }
    return prefix==suffix;
    }
};