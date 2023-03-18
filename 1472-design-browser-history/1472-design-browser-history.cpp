class BrowserHistory {
public:
    vector<string> history;
    int currentIdx;
    int rightBoundary;
    
    BrowserHistory(string homepage) {
        history.push_back(homepage);
        currentIdx = 0;
        rightBoundary = 0;
    }
    
    void visit(string url) {
        currentIdx += 1;
        
        if(currentIdx <= (history.size() - 1)){
            history[currentIdx] = url;
        }     
        else{
            history.push_back(url);
        }
        
        rightBoundary = currentIdx;
    }
    
    string back(int steps) {
        currentIdx = max(currentIdx - steps, 0);
        return history[currentIdx];
    }
    
    string forward(int steps) {
        currentIdx = min(currentIdx + steps, rightBoundary);
        return history[currentIdx];
    }
};

/**
 * Your BrowserHistory object will be instantiated and called as such:
 * BrowserHistory* obj = new BrowserHistory(homepage);
 * obj->visit(url);
 * string param_2 = obj->back(steps);
 * string param_3 = obj->forward(steps);
 */