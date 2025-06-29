class Solution {
public:
    int longestPalindrome(vector<string>& words) {
        unordered_map<string,int> mp;
        int n=words.size();
        //precomputation
        for(int i=0;i<n;i++){
            mp[words[i]]++;
        }
        bool flag=0;
        int count=0;
        for(int i=0;i<n;i++){
            if(words[i][0]==words[i][1]){
                flag=1;
                continue;
            }
            string temp=words[i];
            reverse(temp.begin(),temp.end());
            if(mp.find(temp)!=mp.end()){
                count+=2;
                mp.erase(words[i]);
                mp.erase(temp);
            }
            else{
                mp.erase(words[i]);
            }
        }
        if(flag==1){
            count+=1;
        }
        return count*2;
    }
};