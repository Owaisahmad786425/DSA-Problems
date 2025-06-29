class Solution {
    string fun(int n){
        if(n==1){
            return "1";
        }
        string s=fun(n-1);
        string temp="";
        int count=1;
        for(int i=0;i<s.size();i++){
            if(i==s.size()-1){
                temp+=to_string(count)+s[i];
                break;
            }
            if(s[i]!=s[i+1]){
               temp+=to_string(count)+s[i];
               count=1;
               continue;
                }
                count++;
        }
       return temp;
    }
public:
    string countAndSay(int n) {
   return fun(n);
    }
};