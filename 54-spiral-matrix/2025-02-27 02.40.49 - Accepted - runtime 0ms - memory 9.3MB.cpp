class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int n=matrix.size();
        int m=matrix[0].size();
        vector<int> res;


        if(n==1 && m==1){
            res.push_back(matrix[0][0]);
            return res;
        }
        if(n==1){
            for(int i=0;i<m;i++){
                res.push_back(matrix[0][i]);
            }
            return res;

        }
        else if(m==1){
            for(int i=0;i<n;i++){
                res.push_back(matrix[i][0]);
            }
            return res;
        }
   pair<int,int> t1,t2,t3,t4;
 t1={0,0};
 t2={0,m-1};
 t3={n-1,m-1};
 t4={n-1,0};
bool flag=true;

while(flag==true){
    bool f=0;
for(int i=t1.second;i<t2.second;i++){
    f=1;
 res.push_back(matrix[t1.first][i]);
}
for(int i=t2.first;i<t3.first;i++){
     f=1;
    res.push_back(matrix[i][t2.second]);
}
for(int i=t3.second;i>t4.second;i--){
     f=1;
    res.push_back(matrix[t3.first][i]);
}
for(int i=t4.first;i>t1.first;i--){
     f=1;
    res.push_back(matrix[i][t4.second]);
}
//think of the stopping case and u are done owais
t1={t1.first+1,t1.second+1};
t2={t2.first+1,t2.second-1};
t3={t3.first-1,t3.second-1};
t4={t4.first-1,t4.second+1};
if(t1==t2 && t2==t3 && t3==t4 && t4==t1){
    res.push_back(matrix[t1.first][t1.second]);
    break;
}
if(t3.second<t4.second || t1.second>t2.second || t1.first>t4.first || t2.first>t3.first){
    break;
}
if(t1.second==t2.second && t2.second==t3.second && t3.second==t4.second && t4.second==t1.second){
for(int i=t1.first;i<=t4.first;i++){
    res.push_back(matrix[i][t1.second]);
}
break;
}
if(t1==t4 && t2==t3){
    for(int i=t1.first;i<=t2.second;i++){
        res.push_back(matrix[t1.first][i]);
    }
    break;
}
if(f==0){
    break;
}


}
return res;

    }
};