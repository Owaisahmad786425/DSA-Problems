class Solution {
public:
    string removeOccurrences(string s, string part) {
       stack<char> st; 
       string res;
       int n=s.size();
       int m=part.size();
       for(int i=0;i<n;i++){
        st.push(s[i]);
        string  temp;
        if(st.size()>=m){
            for(int j=0;j<m;j++){
                temp.push_back(st.top());
                st.pop();
            }
            reverse(part.begin(),part.end());
            if(temp!=part){
                for(int j=m-1;j>=0;j--){
                    st.push(temp[j]);
                }
            }
             reverse(part.begin(),part.end());
        }
       
       }

       while(!st.empty()){
        res.push_back(st.top());
        st.pop();
       }
       reverse(res.begin(),res.end());
       return res;
    }
};