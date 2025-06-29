class Solution {
    bool check(char a){
        if(a=='a' || a=='i'||a=='e'||a=='o' || a=='u'){
            return true;
        }
        return false;
    }
public:
    long long countOfSubstrings(string word, int k) {
        long long res=0;
        int n=word.size();
        vector<int> pre_compute(n);
        int last_seen=n;
        for(int i=n-1;i>=0;i--){
            if(check(word[i])){
                pre_compute[i]=last_seen;
            }
            else{
                pre_compute[i]=last_seen;
                last_seen=i;
            }
        }
     map<char,int> mp;
     int l=0;
     int r=0;
     int const_count=0;
     while(r<n){
        if(check(word[r])){
            mp[word[r]]++;
        }
        else{
       const_count++;
        }
        while(const_count>k){
            if(check(word[l])){
                mp[word[l]]--;
                if(mp[word[l]]==0){
                    mp.erase(word[l]);
                }
            }
            else{
                const_count--;
            }
            l++;
        }
        while(mp.size()==5 && const_count==k){
            res+=(pre_compute[r]-r);
            if(check(word[l])){
                mp[word[l]]--;
                if(mp[word[l]]==0){
                    mp.erase(word[l]);
                }

            }
            else{
                const_count--;
            }
l++;
        }
        r++;
     }

return res;
    }
};