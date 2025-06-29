class Solution {
public:
    int maxDiff(int num) {
        //kl ke trh hi hai ik baar max nikalna hai ik baar min nikalna hai
        string s1=to_string(num);
        string s2=to_string(num);
        int n=s1.size();
        char x1=' ',y1=' ',x2=' ',y2=' ';
        for(int i=0;i<n;i++){
            if(s1[i]=='9'){
                continue;
            }
            x1=s1[i];
            break;
        }
        for(int i=0;i<n;i++){
            if(s1[i]==x1){
                s1[i]='9';
            }
        }
        bool flag=0;
        for(int i=0;i<n;i++){
            if(s2[i]!='1' && i==0){
                flag=true;
                x2=s2[i];
                break;
            }
           else if(s2[i]=='1' || s2[i]=='0'){
            continue;
           }
           x2=s2[i];
            break;
        }
        for(int i=0;i<n;i++){
            if(x2==s2[i] && flag){
                s2[i]='1';
            }
            else if(x2==s2[i] && !flag){
                s2[i]='0';
            }
        }
       int num1=stoi(s1);
       int num2=stoi(s2);
       return num1-num2;
    }
};