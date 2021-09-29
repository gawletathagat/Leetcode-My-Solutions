class Trie {
public:
    
    struct TrieNode
    {
       TrieNode* child[26] ;
       bool isEnd ;  // default false ;
    };
    
    TrieNode* root ;
    
    Trie() 
    {
        //https://www.youtube.com/watch?v=BN-SUKeOYC0
        root = new TrieNode() ;
    }
    
    void insert(string word) 
    {
        TrieNode* curr = root ;
        for( int i= 0 ; i<word.size() ; i++)
        {
            char ch = word[i] ;
            
            if( curr->child[ch-'a'] == NULL)
            {
                curr->child[ch-'a'] = new TrieNode() ;
            }
            
           curr = curr->child[ch-'a'] ; 
        }
        
        curr->isEnd = true;  
    }
    
    bool search(string word) 
    {
        TrieNode* curr = root ;
        for( int i= 0 ; i<word.size() ; i++)
        {
            char ch = word[i] ;
            
            if( curr->child[ch-'a']== NULL) return false;
            
            curr = curr->child[ch-'a'] ;
        }
        
        return curr->isEnd ;
        
    }
    
    bool startsWith(string word)
    {
        TrieNode* curr = root ;
        for( int i= 0 ; i<word.size() ; i++)
        {
            char ch = word[i] ;
            
            if( curr->child[ch-'a'] == NULL) return false; 
            
            curr = curr->child[ch-'a'] ;
        }
        return true;
        
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */