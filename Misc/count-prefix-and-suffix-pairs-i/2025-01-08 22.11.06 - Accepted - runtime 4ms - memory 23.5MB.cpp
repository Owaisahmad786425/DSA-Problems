class Solution {
    bool isPrefixAndSuffix(string a, string b){
       int length1=a.size();
       int length2=b.size();
       if(length1>length2){
        return false;
       }
       bool flag=true;
   for(int l1=0,r1=length1-1,l2=0,r2=length2-1;l1<length1 && l2<length2 && r1>=0 && r2>=0 && flag ;l1++,l2++,r1--,r2--){
flag=((a[l1]==b[l2])&&(a[r1]==b[r2]));
   }
   return flag;
    }
public:
    int countPrefixSuffixPairs(vector<string>& words) {
        int n=words.size();
        int count=0;
        for(int i=0;i<n-1;i++){
            for(int j=i+1;j<n;j++){
                if(isPrefixAndSuffix(words[i],words[j])){
                    count++;
                }
            }
        }
        return count;
    }
};