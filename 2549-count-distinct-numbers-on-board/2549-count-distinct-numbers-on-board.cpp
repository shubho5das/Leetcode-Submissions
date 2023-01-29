class Solution {
public:
    int distinctIntegers(int n) {
        int i,cnt,prevCnt,currentCnt;
        
        cnt = 0;
        unordered_set<int> board;
        board.insert(n);
        prevCnt = 1;
        
        while(1){
            unordered_set<int> newBoard;
            for(auto x : board){
                newBoard.insert(x);
                for(i=1 ; i<=x ; i++){
                    if(x%i == 1){
                        newBoard.insert(i);
                    }
                }                
            }
            
            board = newBoard;
            currentCnt = board.size();
            if(currentCnt == prevCnt){
                break;
            }
            
            prevCnt = currentCnt;
        }

        return currentCnt;        
    }
};