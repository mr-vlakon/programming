class MyStack {
public:
    MyStack() {
        
    }
    
    void push(int x) {
        deq.push_back(x);
    }
    
    int pop() {
        int val = deq.back();
        deq.erase(--deq.end());
        return val;
    }
    
    int top() {
        return deq.back();
    }
    
    bool empty() {
        return deq.empty();
    }
private:
    deque<int> deq;

};

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack* obj = new MyStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * bool param_4 = obj->empty();
 */

int main() {

  return 0;  
}
