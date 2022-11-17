class Solution {
public:
    int computeArea(int ax1, int ay1, int ax2, int ay2, int bx1, int by1, int bx2, int by2) {
        int areaA,areaB,common_x1,common_x2,common_y1,common_y2,commonLength,commonBreadth,commonArea,combinedArea;
        
        // 1
        areaA = (ax2 - ax1) * (ay2 - ay1);                
        
        // 2
        areaB = (bx2 - bx1) * (by2 - by1);            
        
        // 3
        common_x1 = max(ax1,bx1);
        common_x2 = min(ax2,bx2);        
        commonLength = max(0,(common_x2 - common_x1));

        common_y1 = max(ay1,by1);
        common_y2 = min(ay2,by2);        
        commonBreadth = max(0,(common_y2 - common_y1));
                
        commonArea = commonLength * commonBreadth;
              
        // Final Answer           
        combinedArea = (areaA + areaB - commonArea);
        return combinedArea;                
    }
};