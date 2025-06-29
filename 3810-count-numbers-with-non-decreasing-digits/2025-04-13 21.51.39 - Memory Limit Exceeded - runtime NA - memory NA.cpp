class Solution {
    bool check(string s){
        for(int i=1;i<s.size();i++){
            if(s[i]<s[i-1]){
                return false;
            }
        }
        return true;
    }
public:
    int countNumbers(string l, string r, int b) {
        vector<string> res;
        int MOD=1000000000+7;
        int count=0;
        int li=stoi(l);
        int ri=stoi(r);
        for(int num=li;num<=ri;num++){
            string temp;
            int num1=num;
            while(num1>=b){
            int t=(num1%b);
               temp.push_back(t+'0');
                num1/=b;
            }
            temp.push_back(num1+'0');
            reverse(temp.begin(),temp.end());
            res.push_back(temp);
        }
        for(int i=0;i<res.size();i++){
          if(check(res[i])){
              count++;
          } 
         }
        return count%MOD;
    }
    
};