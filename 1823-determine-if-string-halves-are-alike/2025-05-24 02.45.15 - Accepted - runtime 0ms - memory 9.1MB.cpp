class Solution {
    bool check(char a){
        if(a=='a' ||a=='e' || a=='i'||a=='o'||a=='u' ||a=='A' ||a=='E' ||a=='I' || a=='O' || a=='U'){
            return true;
        }
        return false;
    }
public:
    bool halvesAreAlike(string s) {
        int n=s.size();
        int half_index=(n/2)-1;
        int half_count;
        int full_count=0;
        for(int i=0;i<n;i++){
            if(check(s[i])){
                full_count++;
            }
          if(i==half_index){
            half_count=full_count;
          }
        }
        if(full_count%2!=0){
         return false;
        }
        return (full_count/2)==half_count;
    }

};