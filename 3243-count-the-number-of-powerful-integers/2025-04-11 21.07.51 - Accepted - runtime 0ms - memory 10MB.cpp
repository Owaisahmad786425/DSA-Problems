class Solution {
    long long solve(string str, string input_suffix,int limit){
    if(str.length()<input_suffix.length()){
        return 0;
    }
    long long count=0;
  string str_suffix=str.substr(str.length()-input_suffix.length());
  int rem_len=str.length()-str_suffix.length();
  for(int i=0;i<rem_len;i++){
    int digit=str[i]-'0';
    if(digit<=limit){
        count+=digit*pow(limit+1,rem_len-i-1);
    }
    else{
        count+=pow(limit+1,rem_len-i);
        return count;
    }
  }
if(str_suffix>=input_suffix){
    count+=1;
}
return count;


    }
public:
    long long numberOfPowerfulInt(long long start, long long finish, int limit, string s) {
        string start_one=to_string(start-1);
        string end_one=to_string(finish);

        return solve(end_one,s,limit)-solve(start_one,s,limit);
    }
};