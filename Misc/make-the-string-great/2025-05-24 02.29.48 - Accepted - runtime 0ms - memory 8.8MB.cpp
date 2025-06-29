class Solution {
public:
    string makeGood(string s) {
        stack<char> st;
        int n=s.size();
        int i=0;
        while(i<n){
            while(!st.empty() && (st.top()==s[i]-32 || st.top()==s[i]+32)){
                st.pop();
                i++;
            }
            if(i<n){
                st.push(s[i]);
            }
            i++;
        }
        string res="";
        while(!st.empty()){
            res+=st.top();
            st.pop();
        }
        reverse(res.begin(),res.end());
        return res;
    }
};