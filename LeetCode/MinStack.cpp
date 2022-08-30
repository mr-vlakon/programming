class MinStack {
public:
    MinStack() {
        
    }
    
    void push(int val) {
        deq.push_back(val);
    }
    
    void pop() {
        if (deq.empty())
            return;
        else {
            deq.erase(--deq.end());
        }
            
    }
    
    int top() {
        if (deq.empty()) {
            return 0;
        } else {
            return deq.back();
        }
    }
    
    int getMin() {
        return *min_element(deq.cbegin(), deq.cend());
    }
private:
    deque<int> deq;
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */
int main() {
  
  return 0;  
}
