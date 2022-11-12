class MedianFinder {
public:    
    static const int inf = 1e9;
    
    double median;
    priority_queue<int> maxHeap;                           // elements <= median
    priority_queue<int,vector<int>,greater<int>> minHeap;  // elements > median
    
    MedianFinder() {
        median = (-inf * 1.0);
    }
    
    void addNum(int num) {
        int sz1,sz2,temp;
        
        // Step 1: Adding num to the DataStream
        sz1 = maxHeap.size();
        sz2 = minHeap.size();
        
        if(num > median){
            if(sz2 > sz1){
                temp = minHeap.top();  // Balancing Operation
                minHeap.pop();                
                maxHeap.push(temp);
            }
            
            minHeap.push(num);
        }
        else{
            if(sz1 > sz2){
                temp = maxHeap.top();  // Balancing Operation
                maxHeap.pop();
                minHeap.push(temp);                
            }
            
            maxHeap.push(num);
        }
        
        // Step 2: Updating the median value
        sz1 = maxHeap.size(), sz2 = minHeap.size();
        
        if((sz1 + sz2)%2 == 0){
            median = (maxHeap.top() + minHeap.top()) / 2.0;
        }
        else{
            if(sz1 > sz2){
                median = (maxHeap.top() * 1.0);
            }
            else{
                median = (minHeap.top() * 1.0);
            }
        }
        
        //cout<<num<<" "<<sz1<<" "<<sz2<<" "<<median<<"\n"; // debugging        
    }
    
    double findMedian() {
        return median;
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */