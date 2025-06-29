class Solution {
public:
    int minMaxDifference(int num) {
        string s1=to_string(num);
        string s2=to_string(num);
        int n=s1.size();
        char el=' ';
        char el2=' ';
        for(int i=0;i<n;i++){
         if(el==' ' && s1[i]!='9'){
            el=s1[i];
         }
         if(el2==' ' && s2[i]!='0'){
            el2=s2[i];
         }
         if(el==s1[i]){
            s1[i]='9';
         }
         if(el2==s2[i]){
            s2[i]='0';
         }
        }
        int n1=stoi(s1);
        int n2=stoi(s2);
        return n1-n2;
    }
};