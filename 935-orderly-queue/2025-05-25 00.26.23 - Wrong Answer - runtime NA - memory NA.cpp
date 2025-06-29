class Solution {
    string fun(string s){
        queue<char> q;
        string temp=s;
        sort(temp.begin(),temp.end());
        for(int i=0;i<s.size();i++){
            q.push(s[i]);
        }
       while(q.front()!=temp[0]){
        char a=q.front();
        q.pop();
        q.push(a);
       }
       temp="";
       while(!q.empty()){
        temp+=q.front();
        q.pop();
       }
       return temp;
    }
public:
    string orderlyQueue(string s, int k) {
      if(k==1){
        return fun(s);
      }

        sort(s.begin(),s.end());
        return s;
    }
};