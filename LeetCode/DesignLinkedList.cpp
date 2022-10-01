class MyLinkedList {
public:
    MyLinkedList() {
        
    }
    
    int get(int index) {
        auto it = lst.cbegin();
        if (index >= lst.size()) return -1;
        while (index) {
            ++it;
            --index;
        }
        return *it;
    }
    
    void addAtHead(int val) {
        lst.insert(lst.cbegin(), val);
    }
    
    void addAtTail(int val) {
        lst.insert(lst.cend(), val);
    }
    
    void addAtIndex(int index, int val) {
        if (index > lst.size()) return;
        auto it = lst.cbegin();
        while (index) {
            ++it;
            --index;
        }
        lst.insert(it, val);
    }
    
    void deleteAtIndex(int index) {
        if (index >= lst.size()) return;
        auto it = lst.cbegin();
        while (index) {
            ++it;
            --index;
        }
        lst.erase(it);        
    }
private:
    list<int> lst;
};

/**
 * Your MyLinkedList object will be instantiated and called as such:
 * MyLinkedList* obj = new MyLinkedList();
 * int param_1 = obj->get(index);
 * obj->addAtHead(val);
 * obj->addAtTail(val);
 * obj->addAtIndex(index,val);
 * obj->deleteAtIndex(index);
 */

int main() {
  
  
  return 0;  
}
