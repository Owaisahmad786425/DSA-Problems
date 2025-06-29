class Solution {
    int n;
   
    void fun(int len,int &dig_val,vector<int> &digits, vector<bool> &vis,set<int> &st){
        //base case
        if(len==3){
        st.insert(dig_val);
        return;
        }
        for(int i=0;i<n;i++){
            if(len==0 && digits[i]==0){
                continue;
            }
            else if(len==2 && digits[i]%2!=0){
                continue;
            }
            else if(vis[i]){
                continue;
            }
            vis[i]=1;
            dig_val=(dig_val*10)+digits[i];
            fun(len+1,dig_val,digits,vis,st);
            vis[i]=0;
            dig_val/=10;
        }
    }
public:
    vector<int> findEvenNumbers(vector<int>& digits) {
        sort(digits.begin(),digits.end());
         n=digits.size();
         set<int> st;
         vector<bool> vis(n,false);
         int dig_val=0;
         int len=0;
         fun(len,dig_val,digits,vis,st);
         vector<int> res;
        for(auto it:st){
            res.push_back(it);

        }
return res;

    }
};