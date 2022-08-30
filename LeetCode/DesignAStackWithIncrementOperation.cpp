class CustomStack {
public:
    CustomStack(int maxSize) {
        v.reserve(maxSize);
        max = maxSize;
    }
    
    void push(int x) {
        if (v.size() < max) {
            v.push_back(x);    
        }
    }
    
    int pop() {
        if (v.size() == 0) return -1;
        int val = v.back();
        v.erase(--v.end());
        return val;
    }
    
    void increment(int k, int val) {
        auto end = (k > v.size()) ? v.end() : v.begin() + k;
        for_each(v.begin(), end, [=] (int &x) {
            x += val;
        });
    }
private:
    int max;
    vector<int> v;
};

/**
 * Your CustomStack object will be instantiated and called as such:
 * CustomStack* obj = new CustomStack(maxSize);
 * obj->push(x);
 * int param_2 = obj->pop();
 * obj->increment(k,val);
 */

int main() {
  
  return 0;  
}
