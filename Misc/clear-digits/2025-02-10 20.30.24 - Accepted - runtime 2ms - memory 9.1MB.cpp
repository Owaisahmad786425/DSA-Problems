class Solution {
    bool is_digit(char a){
   if(a=='1' || a=='2'|| a=='3'|| a=='4'|| a=='5'|| a=='6' || a=='7' || a=='8' || a=='9' ||a=='0'){
    return true;
   }
   return false;
    }
public:
    string clearDigits(string s) {
       stack<char> st;
    int n=s.size();
    for(int i=0;i<n;i++){
        if(!is_digit(s[i])){
    st.push(s[i]);
        }
        else{
            st.pop();
        }
    }
 string res;
 while(!st.empty()){
    res.push_back(st.top());
    st.pop();
 }
 reverse(res.begin(),res.end());
return res;
    }
};