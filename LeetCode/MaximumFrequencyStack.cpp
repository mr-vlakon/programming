class FreqStack {
public:
    FreqStack() {
        
    }
    
    void push(int val) {
        ++um[val];
        pq.push({um[val], {id, val}});
        ++id;
    }
    
    int pop() {
        auto top = pq.top();
        um[top.second.second] -= 1;
        pq.pop();
        return top.second.second;
    }
private:
    int id = 0;
    priority_queue<pair<int, pair<int, int>>> pq;
    unordered_map<int, int> um;
};

/**
 * Your FreqStack object will be instantiated and called as such:
 * FreqStack* obj = new FreqStack();
 * obj->push(val);
 * int param_2 = obj->pop();
 */

int main() {
  
  
  
  return 0;  
}
