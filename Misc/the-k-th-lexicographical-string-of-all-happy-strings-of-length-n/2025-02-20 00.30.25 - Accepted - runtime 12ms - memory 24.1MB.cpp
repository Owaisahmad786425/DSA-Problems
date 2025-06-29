class Solution {
void fun(int index, string &res, int n,vector<string>&vec){
//base case afterwards
if(index==n){
vec.push_back(res);
return;
}

for(int i=0;i<3;i++){
    if(index==0){
        res[index]='a'+i;
        fun(index+1,res,n,vec);
    }
    else if(index>0){
    if('a'+i!=res[index-1]){
        res[index]='a'+i;
        fun(index+1,res,n,vec);
    }


    }
}


}


public:
    string getHappyString(int n, int k) {
        string res(n,'a');
        vector<string> vec;
        fun(0,res,n,vec);
        if(k>vec.size()){
            return "";
        }
        return vec[k-1];
        
    }
};