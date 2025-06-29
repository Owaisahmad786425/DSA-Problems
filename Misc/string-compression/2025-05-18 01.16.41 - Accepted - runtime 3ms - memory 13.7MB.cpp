class Solution {
public:
    int compress(vector<char>& chars) {
        int n=chars.size();
        int i=0;
        int j=0;
        int count=0;
        string s="";
        while(j<n){
            if(chars[i]==chars[j]){
                count++;
                j++;
            }
            else{
                if(count>1){
                    s+=chars[i];
                    s+=to_string(count);
                }
                else{
                    s+=chars[i];
                }
                count=0;
                i=j;
            }
        }
      if(count>0 && count==1){
        s+=chars[i];
      }
      else if(count>0 && count>1){
        s+=chars[i];
        s+=to_string(count);
      }
      for(int k=0;k<s.size();k++){
        chars[k]=s[k];
      }
      return s.size();
    }
};