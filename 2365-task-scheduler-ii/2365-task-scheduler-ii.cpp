class Solution {
public:
    long long taskSchedulerII(vector<int>& tasks, int gap) {
        long long i,n,currentIdx;
        n = tasks.size();
        
        unordered_map<long long,long long> M; // {task,lowestAllowedIdx}
        
        currentIdx = -1;
        for(i=0 ; i<n ; i++){
            if((M.find(tasks[i]) == M.end()) || ((currentIdx + 1) >= M[tasks[i]])){
                currentIdx++;
            }
            else{
                currentIdx = M[tasks[i]];
            }
            
            M[tasks[i]] = (currentIdx + gap + 1);
        }
                
        return (currentIdx + 1);
    }
};