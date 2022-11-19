class Point{
public:    
    int x;
    int y;

    // Consturctor
    Point(int x,int y){
        this->x = x;
        this->y = y;
    }
};

class Solution {
public:        
    static bool compare(Point a,Point b){
        if(a.y == b.y){
            return(a.x < b.x);
        }
        
        return (a.y < b.y);
    }
    
    int checkConvex(Point a,Point b,Point c){
        int crossProduct = (b.x-a.x)*(c.y-a.y) - (b.y-a.y)*(c.x-a.x);
        
        if(crossProduct > 0){
            // Points are convex
            return 1;
        }
        else if(crossProduct < 0){
            // Points are NOT convex (concave)
            return -1;
        }
        else{
            // Points are linear
            return 0;
        }
    }
        
    vector<vector<int>> outerTrees(vector<vector<int>>& trees) {
        int n,i;
        n = trees.size();
        
        vector<Point> points;        
        for(i=0 ; i<n ; i++){
            Point p(trees[i][0],trees[i][1]);
            points.push_back(p);
        }
                
        if(n == 1){
            return trees;
        }
        
        // 1
        sort(points.begin(),points.end(),compare);
                
        // 2
        vector<vector<int>> solution;        
        set<vector<int>> duplicates;
        
        stack<Point> hull;
        hull.push(points[0]);
        hull.push(points[1]);        
        
        // Lower Hull  (clockwise traversal)
        for(i=2 ; i<n ; i++){
            Point top = hull.top();
            hull.pop();
            while(hull.size() >= 1 && checkConvex(hull.top(),top,points[i]) < 0){
                top = hull.top();
                hull.pop();
            }            
            hull.push(top);            
            hull.push(points[i]);
        }
        
        // Upper Hull  (anti-clockwise traversal)
        for(i=(n-2) ; i>=0 ; i--){
            Point top = hull.top();
            hull.pop();
            while(hull.size() >= 1 && checkConvex(hull.top(),top,points[i]) < 0){
                top = hull.top();
                hull.pop();
            }            
            hull.push(top);            
            hull.push(points[i]);             
        }

        
        while(hull.size() >= 1){
            Point p = hull.top();
            hull.pop();
            
            if(duplicates.find({p.x, p.y}) != duplicates.end()){
                continue;
            }
            
            duplicates.insert({p.x, p.y});
            solution.push_back({p.x,p.y});            
        }
        
        return solution;
    }
};