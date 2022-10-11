class Solution {
public:
    int minNumberOfHours(int currentEnergy, int currentExperience, vector<int>& energy, vector<int>& experience) {
        int n,i,cnt;
        n = energy.size();
        
        cnt = 0;
        for(i=0 ; i<n ; i++){
            while(currentEnergy <= energy[i]){
                cnt++;
                currentEnergy++;
            }
            while(currentExperience <= experience[i]){
                cnt++;
                currentExperience++;
            }
            
            currentEnergy -= energy[i];
            currentExperience += experience[i];
        }
        
        return cnt;
    }
};