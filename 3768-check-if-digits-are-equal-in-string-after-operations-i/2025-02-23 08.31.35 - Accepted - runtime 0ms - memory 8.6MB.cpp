class Solution {
public:
    bool hasSameDigits(string s) {
        string t=s;
        while(t.size()>2){
            for(int i=0;i<t.size();i++){
                if(i==t.size()-1){
                    t.pop_back();
                }
                else{
                    t[i]=(((t[i]-'0')+(t[i+1]-'0'))%10)+'0';
                }
                
            }
        }
        return t[0]==t[1];
    }
};