class Solution {
    int MOD=1e9+7;
public:
    int lengthAfterTransformations(string s, int t) {
        vector<long long> freq(26,0);
        for(int i=0;i<s.size();i++){
            freq[s[i]-'a']++;
        }

        for(int i=0;i<t;i++){
            vector<long long> hash(26,0);
            for(int j=0;j<26;j++){
                if(j==25 && freq[j]>0){
                    hash[0]=(hash[0]+freq[j])%MOD;
                    hash[1]=(hash[1]+freq[j])%MOD;
                    break;
                }
                else if(freq[j]>0){
                    hash[j+1]=(hash[j+1]+freq[j])%MOD;
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