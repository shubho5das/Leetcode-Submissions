class BrowserHistory {
public:
    vector<string> history;
    int currentIdx;
    
    BrowserHistory(string homepage) {
        history.push_back(homepage);
        currentIdx = 0;
    }
    
    void visit(string url) {
        while(history.size() > (currentIdx + 1)){
            history.pop_back();
        }
        
        history.push_back(url);
        currentIdx++;        
    }
    
    string back(int steps) {
        currentIdx = max(currentIdx - steps, 0);
        return history[currentIdx];
    }
    
    string forward(int steps) {
        int n = history.size();
        currentIdx = min(currentIdx + steps, (n-1));
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