class Solution {
public:
    bool areAlmostEqual(string s1, string s2) {
        int n=s1.size();
        int index1,index2,count=0;
        if(s1==s2){
            return  true;
        }
        char first,second;
        for(int i=0;i<n;i++){
         if(s1[i]!=s2[i]){
count++;
            if(count==1)
            index1=i;
          if(count==2){
index2=i;
          }
         }
         
        }
        first=s1[index1];
        second=s1[index2];
        if(count==2){
            if(first==s2[index2] && second==s2[index1])
           return true;
        }

        return false;

    }
};