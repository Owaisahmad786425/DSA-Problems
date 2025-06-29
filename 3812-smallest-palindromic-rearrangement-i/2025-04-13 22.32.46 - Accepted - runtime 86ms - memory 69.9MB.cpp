class Solution {
public:
    string smallestPalindrome(string s) {
       int n=s.size();
        if(n==1||n==2){
            return s;
        }
        if(n%2==0){
            int d=(n/2);
            string temp=s.substr(0,d);
            sort(temp.begin(),temp.end());
            string right=temp;
            reverse(right.begin(),right.end());
                string full="";
                full=temp+right;
                return full;
            
        }
        int d=(n/2);
        string temp=s.substr(0,d);
        sort(temp.begin(),temp.end());
        string right=temp;
        temp.push_back(s[d]);
        reverse(right.begin(),right.end());
        string full="";
        full=temp+right;
        return full;
    }
};