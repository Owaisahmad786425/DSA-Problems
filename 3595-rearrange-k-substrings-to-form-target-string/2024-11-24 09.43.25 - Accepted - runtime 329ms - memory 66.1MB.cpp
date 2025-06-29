class Solution {
public:
    bool isPossibleToRearrange(string s, string t, int k) {
map<string, int> mp;
int l = s.size() / k;  
int count = 0;
string temp;
        if(s==t) return true;
        if(l==1){
            return true;
        }
for (int i = 0; i < s.size(); i++) {
    count++;
    temp.push_back(s[i]);  
    if (count == l) {     
        mp[temp]++;        
        temp.clear();     
        count = 0;         
    }
}

count = 0;
temp.clear();  // Clear temp before reusing
for (int i = 0; i < t.size(); i++) {
    count++;
    temp.push_back(t[i]);  // Build substring from string t
    if (count == l) {      // If substring reaches size l
        if (mp.find(temp) == mp.end() || mp[temp]==0) {  // Check if substring exists in map
            return false;  // Return false if not found
        }
        else{
     mp[temp]--;
        }
        temp.clear();      // Reset temp for next substring
        count = 0;         // Reset count
    }
}

return true;  // If all checks pass, return true
    }
};