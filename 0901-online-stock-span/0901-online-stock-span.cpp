class StockSpanner {
public:
    int i;
    stack<pair<int,int>> st; // {i,price}
        
    StockSpanner() {
        i = 0; 
    }
    
    int next(int x) {
        int span;
        
        // Speical Case: Day 0        
        if(i == 0){
            span = 1;
            
            st.push({i,x});                        
            i++;
            return span;
        }

        while(st.size() >= 1 && x >= (st.top()).second ){
            st.pop();
        }

        if(st.empty()){
            span = (i + 1);            
        }
        else{
            span = (i - (st.top()).first);
        }
        
        st.push({i,x});
        i++;
        return span;
    }
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */