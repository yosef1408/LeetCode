
struct Node{
    int key;
    int value;
    Node* next;
    Node* previous;
    
    Node():key(-1),value(-1),next(nullptr),previous(nullptr){};
    Node(int key, int val):key(key),value(val),next(nullptr),previous(nullptr){};
    
};

class LRUCache {

private:
    
    int capacity;
    unordered_map<int,Node*> hashTable;
    Node* head; // Most recently used
    Node* tail; // Least recently used
    
public:
    
    void insert(Node* first){
        
        Node* tmp = head->next;
        head->next = first;
        first->previous = head;
        first->next = tmp;
        tmp->previous = first;
    }
    
    void remove(Node* node){
        (node->next)->previous = node->previous;
        (node->previous)->next = node->next;
    }
    
    LRUCache(int capacity):capacity(capacity) {
        
        head = new Node(0, 0); // Dummy head
        tail = new Node(0, 0); // Dummy tail
        head->next = tail;
        tail->previous = head;
        
    }
    
    ~LRUCache(){
        Node* current = head;
        while(current)
        {
            Node* next = current->next;
            delete(current);
            current = next;
        }
    }
    
    int get(int key) {
        if(hashTable.find(key) != hashTable.end()){
            remove(hashTable[key]);
            insert(hashTable[key]);
            return hashTable[key]->value;
        }
        return -1;
        
    }
    
    void put(int key, int value) {
        if(hashTable.find(key) != hashTable.end()){
            remove(hashTable[key]);
            insert(hashTable[key]);   
            hashTable[key]->value =(value);    
        }
        else{
            if(hashTable.size() < capacity ){
                hashTable[key] = new Node(key,value);
                insert(hashTable[key] );
            }
            else{
                Node* lru = tail->previous;
                
                hashTable.erase(lru->key);
                remove(lru);
                delete(lru);
                hashTable[key] = new Node(key,value);
                insert(hashTable[key]);
            }
        }
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */