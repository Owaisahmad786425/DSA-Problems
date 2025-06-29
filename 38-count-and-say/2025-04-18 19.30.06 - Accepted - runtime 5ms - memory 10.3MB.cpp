class Solution {
    void fun(int n,string &s){
        if(n==1){
            s+="1";
            return;
        }
        fun(n-1,s);
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
        s=temp;
    }
public:
    string countAndSay(int n) {
      string s="";
    fun(n,s);
    return s;
    }
};