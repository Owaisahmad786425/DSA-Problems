class Solution {
public:
    bool canConstruct(string s, int k) {
        int n=s.size();
        map<char,int> mp;
        if(n<k){
            return false;
        }
        //these were edge case;
        if(n==k){
            return true;
        }
        for(int i=0;i<n;i++){
            mp[s[i]]++;
        }
    for (auto it = mp.begin(); it != mp.end(); ) {
    if (it->second % 2 == 0) {
        it = mp.erase(it);
    } else {
        ++it;
    }
}
        if(mp.size()<=k){
            return true;
        }
        return false;

    }
};