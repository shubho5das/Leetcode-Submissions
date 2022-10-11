class LUPrefix {
public:
    bool visited[100007];
    int idx;
    
    LUPrefix(int n) {
        int i;
        
        for(i=0 ; i<=(n+2) ; i++){
            visited[i] = false;
        }        
        visited[0] = true;
        
        idx = 1;
    }
    
    void upload(int video) {
        visited[video] = true;
        while(visited[idx]){
            idx++;
        }
    }
    
    int longest() {
        return (idx - 1);
    }
};

/**
 * Your LUPrefix object will be instantiated and called as such:
 * LUPrefix* obj = new LUPrefix(n);
 * obj->upload(video);
 * int param_2 = obj->longest();
 */