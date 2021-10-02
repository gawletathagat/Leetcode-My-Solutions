class Trie {
public:
    
    struct TrieNode
    {
        TrieNode* child[26] ;
        bool endPoint = false;
    };
    
    TrieNode* root ;
    
    Trie() 
    {
        root = new TrieNode() ;
    }
    
    void insert(string word)
    {
       TrieNode* curr = root ;
        for( int i= 0 ; i<word.size() ; i++)
        {
            if( curr->child[word[i]-'a'] == NULL)
            {
                curr->child[word[i]-'a'] = new TrieNode() ;
            }
            curr = curr->child[word[i]-'a'] ;
        }
        
        curr->endPoint = true;
    }
    
    bool search(string word)
    {
        TrieNode* curr = root ;
        for( int i= 0 ; i<word.size() ; i++)
        {
            if( curr->child[word[i]-'a'] != NULL )
            {
                curr = curr->child[word[i]-'a'] ;
            }
            else 
                return false ;
        }
        
        return curr->endPoint ;
    }
    
    bool startsWith(string word)
    {
        TrieNode* curr = root ;
        for( int i= 0 ; i<word.size() ; i++)
        {
            if( curr->child[word[i]-'a'] != NULL) 
            {
                curr = curr->child[word[i]-'a'] ;
            }
            else
                return false; 
        }
        
        return true ;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */