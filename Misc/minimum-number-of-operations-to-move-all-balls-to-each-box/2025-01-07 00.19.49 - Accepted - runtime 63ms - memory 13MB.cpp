class Solution {
public:
    vector<int> minOperations(string boxes) {
        vector<int> vec;
        int n=boxes.size();
        //precomputation
        for(int i=0;i<n;i++){
            if(boxes[i]=='1'){
                vec.push_back(i);
            }
        }
        vector<int> result;
        for(int i=0;i<n;i++){
int sum=0;
           for(int j=0;j<vec.size();j++){
            if(i<vec[j]){
          sum+=(vec[j]-i);  
            }
            else if(i>vec[j]){
                sum+=(i-vec[j]);
            }
           }
           result.push_back(sum); 

        }
        return result;
    }
};