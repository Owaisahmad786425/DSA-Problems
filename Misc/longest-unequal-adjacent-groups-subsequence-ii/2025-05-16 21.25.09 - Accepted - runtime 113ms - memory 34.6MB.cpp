class Solution {
     void fun(vector<string> &res,int index,vector<string> &words,vector<int> &hash){
        //backtracking function
       if(index==hash[index]){
        res.push_back(words[index]);
        return;
       } 

       res.push_back(words[index]);
       fun(res,hash[index],words,hash);


     }

    bool calculate(string a, string b){
        int count=0;
        for(int i=0;i<a.size();i++){
            if(a[i]!=b[i]){
                count++;
                if(count>1){
                    return false;
                }
            }
        }
        return true;
    }
public:
    vector<string> getWordsInLongestSubsequence(vector<string>& words, vector<int>& groups) {
        vector<string> res;
        int n=words.size();
        vector<int> dp(n,1);
        vector<int> hash(n);
        //initialize the hash value
        for(int i=0;i<n;i++){
            hash[i]=i;
        }

        //apply dp on strings
        for(int curr=0;curr<n;curr++){
            int maxi=0;
            int max_index=1e9;
            for(int prev=0;prev<curr;prev++){
                if(words[curr].size()==words[prev].size() && calculate(words[curr],words[prev]) && groups[prev]!=groups[curr]){
                 if(maxi<dp[prev]){
                    maxi=dp[prev];
                    max_index=prev;
                 }
                }
            }
            dp[curr]=maxi+1;
            if(max_index!=1e9){
            hash[curr]=max_index;
            }
        }
        int maxi=dp[0];
        int index=0;
        for(int i=1;i<n;i++){
            if(dp[i]>maxi){
                maxi=max(maxi,dp[i]);
                index=i;
            }
        }
        //backtraing code
        fun(res,index,words,hash);
        reverse(res.begin(),res.end());
        return res;
    }
};