class MyQueue {
public:
    MyQueue() {
        
    }
    
    void push(int x) {
        deq.push_back(x);
    }
    
    int pop() {
        int val = deq.front();
        deq.erase(deq.begin());
        return val;
    }
    
    int peek() {
        return deq.front();
    }
    
    bool empty() {
        return deq.empty();
    }
private:
    deque<int> deq;
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */

int main() {
  
  return 0; 
}
