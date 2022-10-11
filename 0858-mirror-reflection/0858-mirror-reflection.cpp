class Solution {
public:
    int mirrorReflection(int p, int q) {
        int current;
        
        current = 0;
        bool rightWall = false;
        bool up = true;
        while(1){
            
            // Moving the laser
            if(current + q > p){
                up = !up;
            }            
            rightWall = !rightWall;            
            current = (current + q)%p;
            
            
            // Checking
            if(current == 0){
                if(rightWall && !up){
                    return 0;
                }
                else if(rightWall && up){
                    return 1;
                }
                else if(!rightWall && up){
                    return 2;
                }
            }            
        }
    }
};