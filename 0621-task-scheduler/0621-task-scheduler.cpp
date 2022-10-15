class Solution {
public:
    int leastInterval(vector<char>& tasks, int gap){
        int i,j,n,cnt,taskLeft,intervalLen;
        n = tasks.size();
        
        // 1
        vector<int> freq(26,0);
        for(i=0 ; i<n ; i++){
            freq[(tasks[i] - 'A')]++;  
        }
        
        sort(freq.begin(),freq.end(),greater<int>());    // Note: What the tasks are, no longer matter. Only the frequency values are what we are concerned with.
                
        // 2
        intervalLen = (gap + 1);
        taskLeft = n;
        
        cnt = 0;
        while(taskLeft > 0){                                                
            sort(freq.begin(),freq.end(),greater<int>());           
            
            j = 0;
            for(i=0 ; i<intervalLen ; i++){
                while(j<26 && freq[j] == 0){
                    j++;                    
                }
                
                if(j < 26){
                    freq[j]--;
                    taskLeft--;
                }
                cnt++;
                j++;
                
                if(taskLeft == 0){
                    break;
                }
            }
        }
        
        return cnt;
    }
};