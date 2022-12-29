class RandomizedSet {
public:
    vector<int> nums;
    unordered_map<int,int> M; // {val,idx}
    int sz;
    
    // Constructor
    RandomizedSet() {
        sz = 0;        
    }
    
    // Functions
    bool insert(int val) {
        if(M.find(val) != M.end()){
            return false;
        }
        else{
            nums.push_back(val);
            sz++;
            
            M[val] = (sz - 1);            
            
            return true;
        }
    }
    
    bool remove(int val) {
        int valPos,last,lastPos;
        
        if(M.find(val) == M.end()){
            return false;
        }
        else{
            last = nums[sz - 1];
            lastPos = M[last];
            valPos = M[val];
            
            nums[valPos] = last;
            M[last] = valPos;
            
            nums.pop_back();
            sz--;
            auto it = M.find(val);
            M.erase(it);
            
            return true;
        }                        
    }
    
    int getRandom() {    
        int idx = (rand() % sz);
        return nums[idx];                
    }
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */