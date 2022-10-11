class Solution {
public:
    int countDaysTogether(string arriveAlice, string leaveAlice, string arriveBob, string leaveBob){
        int month,day,s1,e1,s2,e2,s,e,togetherDays;        
        int monthIndex[] = {-1,0,31,59,90,120,151,181,212,243,273,304,334};
        
        // Alice
        month = stoi(arriveAlice.substr(0,2)), day = stoi(arriveAlice.substr(3,2));
        s1 =  (monthIndex[month] + day);
        
        month = stoi(leaveAlice.substr(0,2)), day = stoi(leaveAlice.substr(3,2));
        e1 =  (monthIndex[month] + day);
        
        // Bob
        month = stoi(arriveBob.substr(0,2)), day = stoi(arriveBob.substr(3,2));
        s2 =  (monthIndex[month] + day);
            
        month = stoi(leaveBob.substr(0,2)), day = stoi(leaveBob.substr(3,2));
        e2 =  (monthIndex[month] + day);
        
        // Answer
        s = max(s1,s2);
        e = min(e1,e2);
        
        togetherDays = max(0,(e - s + 1));
        return togetherDays;        
    }
};