class Solution {
    unordered_map<int,string> mp;
    //storage part done
    void initialize(){
        mp[4]="IV";
        mp[9]="IX";
        mp[40]="XL";
        mp[90]="XC";
        mp[400]="CD";
        mp[900]="CM";
    }
public:
    string intToRoman(int num) {
    initialize();
    string s="";
    while(num>0){
        string temp=to_string(num);
        if(temp.size()==4){
            s+="M";
            num=num-1000;
        }
        else if(temp.size()==3){
            if(temp[0]=='4' || temp[0]=='9'){
                int value=(temp[0]-'0')*100;
                s+=mp[value];
                num=num-value;
            }
            else if(temp[0]<'4'){
                s+="C";
               num=num-100;
            }
            else{
                s+="D";
                num=num-500;
            }
        }
        else if(temp.size()==2){
             if(temp[0]=='4' || temp[0]=='9'){
                int value=(temp[0]-'0')*10;
                s+=mp[value];
                num=num-value;
            }
            else if(temp[0]<'4'){
                s+="X";
               num=num-10;
            }
            else{
                s+="L";
                num=num-50;
            }
        }
      else{
          if(temp[0]=='4' || temp[0]=='9'){
                int value=(temp[0]-'0');
                s+=mp[value];
                num-=value;
            }
            else if(temp[0]<'4'){
                s+="I";
               num=num-1;
            }
            else{
                s+="V";
                num=num-5;
            }
      }
        
    }
return s;

    }
};