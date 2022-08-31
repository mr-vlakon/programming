class FrontMiddleBackQueue {
public:
    FrontMiddleBackQueue() {
    }
    
    void pushFront(int val) {
        deq.push_front(val);
    }
    
    void pushMiddle(int val) {
        if (deq.size() == 0) {
            deq.push_back(val);
            return;
        }
        if (deq.size() == 1) {
            deq.push_front(val);
            return;
        }
        if (deq.size() == 2) {
            auto it = deq.begin() + 1;
            deq.insert(it, val);
            return;
        }
        auto mid = deq.size() / 2;
        deq.insert(deq.begin() + mid, val);
    }
    
    void pushBack(int val) {
        deq.push_back(val);
    }
    
    int popFront() {
        if (deq.size() == 0) return -1;
        int val = *deq.begin();
        deq.erase(deq.begin());
        return val;
    }
    
    int popMiddle() {
        if (deq.size() == 0) {
            return -1;
        }
        if (deq.size() == 1) {
            int val = deq.back();
            deq.erase(deq.begin());
            return val;
        }
        if (deq.size() == 2) {
            auto it = deq.begin();
            int val = *it;
            deq.erase(it);
            return val;
        }
        auto mid = (deq.size() % 2 == 1) ? (deq.size() / 2) : (deq.size() / 2 - 1);
        int val = *(deq.begin() + mid);
        deq.erase(deq.begin() + mid);
        
        return val;
    }
    
    int popBack() {
        if (deq.size() == 0) return -1;
        auto it = deq.end();
        --it;
        int val = *it;
        deq.erase(it);
        return val;
    }
private:
    deque<int> deq;
};

/**
 * Your FrontMiddleBackQueue object will be instantiated and called as such:
 * FrontMiddleBackQueue* obj = new FrontMiddleBackQueue();
 * obj->pushFront(val);
 * obj->pushMiddle(val);
 * obj->pushBack(val);
 * int param_4 = obj->popFront();
 * int param_5 = obj->popMiddle();
 * int param_6 = obj->popBack();
 */

int main() {
  
  
  return 0; 
}
