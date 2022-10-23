class Solution {
public:
    bool haveConflict(vector<string>& event1, vector<string>& event2) {
        int s1,e1,s2,e2,hr,min;
        
        // s1
        hr = stoi(event1[0].substr(0,2)), min = stoi(event1[0].substr(3,2));
        s1 = (60*hr + min);                         
        // e1
        hr = stoi(event1[1].substr(0,2)), min = stoi(event1[1].substr(3,2));
        e1 = (60*hr + min);                 
        // s2
        hr = stoi(event2[0].substr(0,2)), min = stoi(event2[0].substr(3,2));            
        s2 = (60*hr + min);         
        // e2
        hr = stoi(event2[1].substr(0,2)), min = stoi(event2[1].substr(3,2));            
        e2 = (60*hr + min); 
        
        
        if((e2 < s1) || (s2 > e1)){
            return false;
        }
        else{
            return true;
        }
    }
};