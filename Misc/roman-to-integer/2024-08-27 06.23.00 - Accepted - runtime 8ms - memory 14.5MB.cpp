class Solution {
public:
    int romanToInt(string s) {
        map<char,int> mp;
        for(int i=0;i<7;i++){
            if(i==0){
                mp['I']=1;
            }
            if(i==1){
                mp['V']=5;
            }
            if(i==2){
                mp['X']=10;
            }
            if(i==3){
                mp['L']=50;
            }
            if(i==4){
                mp['C']=100;
            }
            if(i==5){
                mp['D']=500;
            }
            if(i==6){
                mp['M']=1000;
            }
        }
        int res=0;
        int i=0;
        while(i<s.size()){
            if(mp[s[i]]>=mp[s[i+1]]){
                res=res+mp[s[i]];
                i=i+1;
                continue;
            }
            else if(mp[s[i]]<mp[s[i+1]]){
                int temp=mp[s[i+1]]-mp[s[i]];
                res=res+temp;
                i=i+2;
            }
        }
        return res;
    }
};