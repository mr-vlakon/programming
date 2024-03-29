class MyCircularDeque {
public:
    MyCircularDeque(int k) : size(k) {
        
    }
    
    bool insertFront(int value) {
        if (deq.size() < size) {
            deq.push_front(value);
            return true;
        }
        return false;
    }
    
    bool insertLast(int value) {
        if (deq.size() < size) {
            deq.push_back(value);
            return true;
        }
        return false; 
    }
    
    bool deleteFront() {
        if (deq.size() == 0) {
            return false;
        }
        deq.erase(deq.cbegin());
        return true;
    }
    
    bool deleteLast() {
        if (deq.size() == 0) {
            return false;
        }
        deq.erase(--deq.cend());
        return true;
    }
    
    int getFront() {
        if (deq.size() == 0) {
            return -1;
        }
        return deq.front();
    }
    
    int getRear() {
        if (deq.size() == 0) {
            return -1;
        }
        return deq.back();        
    }
    
    bool isEmpty() {
        return (deq.size() == 0);
    }
    
    bool isFull() {
        return (deq.size() == size);
    }
private:
    int size = 0;
    deque<int> deq;
};

/**
 * Your MyCircularDeque object will be instantiated and called as such:
 * MyCircularDeque* obj = new MyCircularDeque(k);
 * bool param_1 = obj->insertFront(value);
 * bool param_2 = obj->insertLast(value);
 * bool param_3 = obj->deleteFront();
 * bool param_4 = obj->deleteLast();
 * int param_5 = obj->getFront();
 * int param_6 = obj->getRear();
 * bool param_7 = obj->isEmpty();
 * bool param_8 = obj->isFull();
 */

int main() {
  
  
  
  return 0;  
}
