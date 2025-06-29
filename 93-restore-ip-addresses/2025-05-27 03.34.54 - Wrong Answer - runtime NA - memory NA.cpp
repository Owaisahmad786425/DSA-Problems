class Solution {
    bool validate(string t){
        //for leading zeroes
        if(t.size()>1 && t[0]=='0'){
         return false;
        }
        int num=stoi(t);
        if(num>=0 &&num<=255){
            return true;
        }
        return false;
    }
    void fun(int index,int count,set<string> &res,string str,int n,string s){
     //base case
if(count>4){
    return;
}
     if(index>=n){
        str.pop_back();
        res.insert(str);
        return;
     }
     string temp="";
     for(int i=0;i<3;i++){
        if (index + i >= n) break;
temp += s[index + i];

        if(validate(temp)){
            fun(index+i+1,count+1,res,str+temp+".",n,s);
        }
     }
    }
public:
    vector<string> restoreIpAddresses(string s) {
        set<string> res;
        int n=s.size();
        string str="";
        int count=0;
        fun(0,count,res,str,n,s);
        vector<string> vec;
        for(auto it:res){
            vec.push_back(it);
        }
        return vec;
    }
}; 