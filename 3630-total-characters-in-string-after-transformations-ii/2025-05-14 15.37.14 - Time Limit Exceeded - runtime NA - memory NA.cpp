class Solution {
    const int MOD=1e9+7;
public:
    int lengthAfterTransformations(string s, int t, vector<int>& nums) {
        vector<int> freq(26,0);
        for(int i=0;i<s.size();i++){
          freq[s[i]-'a']++;
          }
          //real transformation
          for(int i=0;i<t;i++){
            vector<int> hash(26,0);
            for(int j=0;j<26;j++){
                if(j==25&&freq[j]>0){
                    int pointer=0;
                    for(int k=0;k<nums[j];k++){
                        hash[pointer]=(freq[j]+hash[pointer])%MOD;
                        pointer++;
                        if(pointer==26){
                            pointer=0;
                        }
                    }

                }
                else if(freq[j]>0){
                    int pointer=j+1;
                    for(int k=0;k<nums[j];k++){
                        hash[pointer]=(freq[j]+hash[pointer])%MOD;
                        pointer++;
                        if(pointer==26){
                            pointer=0;
                        }
                    }
                }
            }
            freq=hash;
          }
int res=0;
for(int i=0;i<26;i++){
    res=(res+freq[i])%MOD;
}
return res;
    }

};