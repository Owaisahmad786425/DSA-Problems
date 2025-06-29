class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        vector<int> res;
        for(int i=digits.size()-1;i>=0;i--){
            if(digits[i]!=9){
                digits[i]=digits[i]+1;
                return digits;
            }
            else if(digits[i]==9){
                digits[i]=0;
            }
        }
        res.push_back(1);
        for(int i=0;i<digits.size();i++){
            res.push_back(digits[i]);
        }
        return res;
    }
};