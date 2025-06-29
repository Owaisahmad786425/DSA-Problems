class Solution {
public:
    int longestPalindrome(vector<string>& words) {
       //first for equals
       int n=words.size();
       int max_odd=0;
       unordered_map<string,int> equals;
       unordered_map<string,int> unequals;
       int res=0;
       for(int i=0;i<n;i++){
        if(words[i][0]==words[i][1]){
           equals[words[i]]++;
        }
        else{
            unequals[words[i]]++;
        }
       }
       for(auto it:equals){
        if(it.second%2!=0){
            max_odd=max(max_odd,it.second);
        }
       }
       res+=max_odd;
       bool flag=0;
       for(auto it:equals){
        if(!flag && it.second==max_odd){
            flag=1;
            continue;
        }
        if(it.second%2!=0){
           res+=(it.second-1);
        }
        else{
            res+=it.second;
        }
       }

//time for unequals
for(int i=0;i<n;i++){
if(equals.find(words[i])!=equals.end()){
    continue;
}
string temp=words[i];
reverse(temp.begin(),temp.end());
if(unequals.find(words[i])!=unequals.end() && unequals.find(temp)!=unequals.end()){
    if(unequals[words[i]]<=unequals[temp]){
        res+=unequals[words[i]]*2;
    }
    else{
        res+=unequals[temp]*2;
    }
    unequals.erase(temp);
    unequals.erase(words[i]);
}
}
return res*2;
    }
};