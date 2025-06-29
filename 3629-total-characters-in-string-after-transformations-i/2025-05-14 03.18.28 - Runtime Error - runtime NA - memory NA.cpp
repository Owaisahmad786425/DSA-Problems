class Solution {
public:
    int lengthAfterTransformations(string s, int t) {
        vector<int> freq(26,0);
        for(int i=0;i<s.size();i++){
            freq[s[i]-'a']++;
        }

        for(int i=0;i<t;i++){
            vector<int> hash(26,0);
            for(int j=0;j<26;j++){
                if(j==25 && freq[j]>0){
                    hash[0]+=freq[j];
                    hash[1]+=freq[j];
                    break;
                }
                else if(freq[j]>0){
                    hash[j+1]+=freq[j];
                }

            }
            freq=hash;
        }
        int res=0;
        for(int i=0;i<26;i++){
        res+=freq[i];
        }
        return res;
    }

};