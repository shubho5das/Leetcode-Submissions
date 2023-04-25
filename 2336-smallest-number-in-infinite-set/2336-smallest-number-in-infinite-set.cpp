class SmallestInfiniteSet {
public:
    int currentSmallest = 1;
    unordered_map<int,bool> isPresent;
    
    SmallestInfiniteSet() {
        int i;
        
        for(i=1 ; i<=2000 ; i++){
            isPresent[i] = true;
        }
    }
    
    int popSmallest() {
        int smallestValue,i;
        
        smallestValue = currentSmallest;
        isPresent[currentSmallest] = false;
        
        i = currentSmallest;
        while(isPresent[i] == false){
            i++;
        }       
        currentSmallest = i;     
        
        return smallestValue;
    }
    
    void addBack(int num) {
        isPresent[num] = true;
        
        if(num < currentSmallest){
            currentSmallest = num;
        }
    }
};

/**
 * Your SmallestInfiniteSet object will be instantiated and called as such:
 * SmallestInfiniteSet* obj = new SmallestInfiniteSet();
 * int param_1 = obj->popSmallest();
 * obj->addBack(num);
 */