class Solution {
bool is_prime(int num){

for(int k=2;k<=sqrt(num);k++){
    if(num%k==0){
        return false;
    }
}
return true;
}

public:
    vector<int> closestPrimes(int left, int right) {
        
 int first=-1;
 int second=-1;
int mini=1e9;
 for(int i=left;i<=right;i++){
    if(is_prime(i) &&i!=1){
        if(first==-1 && second==-1){
            first=i;
        }
        else if(first!=-1 && second==-1){
            second=i;
            mini=min(mini,second-first);
        }
        else if(first!=-1 && second!=-1){
            first=second;
            second=i;
            mini=min(mini,(second-first));
        }
    }
 }
 if(first==-1 || second==-1){
    return {-1,-1};
 }
 first=-1;
 second=-1;
 for(int i=left;i<=right;i++){
   if(is_prime(i) &&i!=1){
        if(first==-1 && second==-1){
            first=i;
        }
        else if(first!=-1 && second==-1){
            second=i;
            if(second-first==mini){
                break;
            }
        }
        else if(first!=-1 && second!=-1){
            first=second;
            second=i;
           if(second-first==mini){
            break;
           }
        }
    }
 }


return {first,second};

    }
};