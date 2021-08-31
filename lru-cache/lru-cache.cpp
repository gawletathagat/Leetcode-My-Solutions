class LRUCache {
public:
    class node 
    {   
        public: 
        int key; 
        int val;
        node* next ;
        node* prev ;
        node( int _key , int _val)
        {
            key = _key ;
            val = _val ;
        }
    };
    
    node* head = new node(-1, -1) ;
    node* tail = new node( -1, -1) ;
    
    int max_cap ;
    unordered_map<int, node* > mp; 
    
    LRUCache(int capacity) 
    {
       max_cap = capacity ;
        head->next = tail ;
        tail->prev = head ;
    }
    
    void add_node( node* newnode)
    {
        node* temp = head->next ;
        newnode->next = temp ;
        newnode->prev = head ;
        head->next = newnode ;
        temp->prev = newnode ;
    }
    
    void delete_node( node* delnode)
    {
        node* DEL_NEXT = delnode->next ;
        node* DEL_PREV = delnode->prev;
        
        DEL_PREV->next = DEL_NEXT ;
        DEL_NEXT->prev = DEL_PREV ;
    }
    
    int get(int key) 
    {
        if( mp.find(key) != mp.end() )
        {
            node* resnode = mp[key] ;
            int res = resnode->val ;
            
            mp.erase( key) ;
            delete_node(resnode) ;
            
            add_node( resnode) ;
            mp[key] = head->next ;
            return res;
        }
        return -1;  
    }
    
    void put(int key, int value)
    {
        //case- 1
        if( mp.find(key) != mp.end() ) 
        {
            node* existingnode = mp[key] ;
            mp.erase( key) ;
            delete_node( existingnode ) ;
        }
        //case- 2
        if( mp.size() == max_cap )
        {
            mp.erase( tail->prev->key ) ;
            delete_node( tail->prev ) ;
        }
        
        add_node( new node(key , value) ) ;
        mp[key] = head->next ;
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */