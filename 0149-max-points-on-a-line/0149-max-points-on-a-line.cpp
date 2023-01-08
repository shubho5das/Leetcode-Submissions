class Solution {
public:        
    int maxPoints(vector<vector<int>>& points) {
        int i,j,k,n,x1,x2,y1,y2,x,y,currentCnt,maxCnt;
        n = points.size();
        
        maxCnt = 1;
        for(i=0 ; i<n ; i++){
            for(j=(i+1) ; j<n ; j++){
                x1 = points[i][0], y1 = points[i][1];
                x2 = points[j][0], y2 = points[j][1];
                
                currentCnt = 2;
                for(k=0 ; k<n ; k++){
                    if(k != i && k != j){
                        x = points[k][0], y = points[k][1];                                                
                        if(((y2 - y1)*(x - x1)) == ((y - y1)*(x2 - x1))){
                            currentCnt++;
                        }
                    }
                }
                
                maxCnt = max(maxCnt,currentCnt);
            }
        }
        
        return maxCnt;        
    }
};