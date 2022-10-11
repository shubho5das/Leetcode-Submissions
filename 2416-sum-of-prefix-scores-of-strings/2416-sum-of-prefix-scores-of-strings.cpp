class node{
public:
    char data;
    unordered_map<char,node*> m;
    bool isTerminal;
    int prefixCnt;  // Number of times we have visited this prefix
    
    // Constructor
    node(char data){
        this->data = data;
        isTerminal = false;
        prefixCnt = 1;
    }    
};

class Solution {
public:    
    void insert(string word,node* &root){
        int i;        
        
        node *current = root;         
        for(i=0 ; i<word.length() ; i++){
            char ch = word[i];            
            if((current->m).find(ch) == (current->m).end()){
                node *n = new node(ch);
                (current->m)[ch] = n;
            }
            else{
                (((current->m)[ch])->prefixCnt)++;
            }
                        
            current = (current->m)[ch];
        }
        
        current->isTerminal = true;        
    }
    
    int countPrefixes(string word,node *root){
        // Implementation almost same as the search() function of the Trie
        int i,cnt;
        
        cnt = 0;
        node *current = root;
        for(i=0 ; i<word.length() ; i++){
            char ch = word[i];         
            cnt += ((current->m)[ch])->prefixCnt;
                                    
            current = (current->m)[ch];
        }
        
        return cnt;
    }
    
    vector<int> sumPrefixScores(vector<string> &words) {
        int n,i,j,cnt;
        n = words.size();
        
        // 1.1: Building the Trie - and maintaining the count of no. of times we visit each prefix
        node *root = new node('\0');
        for(i=0 ; i<n ; i++){
            insert(words[i],root);
        }
        
        // 2
        vector<int> solution(n,0);
        for(i=0 ; i<n ; i++){            
            solution[i] = countPrefixes(words[i],root);            
        }        
        return solution;        
    }
};