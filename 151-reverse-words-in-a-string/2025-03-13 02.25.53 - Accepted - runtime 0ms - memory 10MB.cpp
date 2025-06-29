class Solution {
public:
    string reverseWords(string s) {
             int n=s.size();
        reverse(s.begin(),s.end());
        string ans;
        int start=0;
        int end=n-1;
        while(s[start]==' '){
            start++;
        }
        while(s[end]==' '){
            end--;
        }
 int i=start;
 while(i<=end){
    if(s[i]!=' '){
        int k=i;
        while(i<=end && s[i]!=' '){
            i++;
        }
        for(int j=i-1;j>=k;j--){
            ans+=s[j];
        }
        if(i<=end)
        ans+=' ';
    }
    else if(s[i]==' '){
        i++;
    }
 }
return ans;

    }
};