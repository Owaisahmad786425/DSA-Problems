class Solution {
public:
    long long countGoodIntegers(int n, int k) {
       int d=(n+1)/2;
       int start=pow(10,d-1);
       int res=0;
       int end=pow(10,d)-1;
       unordered_set<string> st;
       //pre_compute
       vector<int> fact(11,1);
       for(int i=1;i<11;i++){
        fact[i]=fact[i-1]*i;
       }
       for(int i=start;i<=end;i++){
        string left_half=to_string(i);
        string full="";
        if(n%2==0){
            string right_half=left_half;
            reverse(right_half.begin(),right_half.end());
            full=left_half+right_half;
        }
        else{
          string right_half=left_half.substr(0,d-1);
          reverse(right_half.begin(),right_half.end());
          full=left_half+right_half;
        }
        long long num=stoll(full);
        if(num%k!=0){
            continue;
        }
      sort(full.begin(),full.end());
      st.insert(full);

       }
       for(auto s:st){
        vector<int> freq(10,0);
        for(char &ch:s){
            freq[ch-'0']++;
        }
        int zeros=freq[0];
        int total=n;
        int non_zeros=total-zeros;
        long long perm=(non_zeros*fact[total-1]);
       
       for(int i=0;i<10;i++){
        perm/=fact[freq[i]];
       }
       res+=perm;


       }
       return res;
    }
};