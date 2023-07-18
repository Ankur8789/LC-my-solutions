class LRUCache {
public:
    class node{
  public:
        int key;
        int val;
        node* prev;
        node* next;
        node(int x,int y){
            key=x;
            val=y;
        }
    };
    int size;
    unordered_map<int, node*>mp;
    node* head=new node(-1,-1);
    node* tail=new node(-1,-1);
    
    
    LRUCache(int capacity) {
        size=capacity;
        head->next=tail;
        tail->prev=head;
        
        
        
    }
    
    int get(int key) {
        if(mp.find(key)!=mp.end()){
            node* ele=mp[key];
            int res=ele->val;
            mp.erase(key);
            deletenode(ele);
            addnode(ele);
            mp[key]=head->next;
            return res;
            
        }
            return -1;
        
    }
    
    void put(int key, int value) {
        if(mp.find(key)!=mp.end()){
            node* existing=mp[key];
            mp.erase(key);
            deletenode(existing);
        }
        if(mp.size()==size){
            mp.erase(tail->prev->key);
            deletenode(tail->prev);
        }
        node* newnode=new node(key,value);
        addnode(newnode);
        mp[key]=head->next;
        
    }
    
    
    void addnode(node* x){
        node* temp=head->next;
        x->next=temp;
         x->prev=head;
        head->next=x;
        temp->prev=x;
        
       
    }
    
    void deletenode(node* x){
        node* prev=x->prev;
        node* next=x->next;
        prev->next=next;
        next->prev=prev;
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */