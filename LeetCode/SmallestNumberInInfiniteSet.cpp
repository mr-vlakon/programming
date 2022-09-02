class SmallestInfiniteSet {
public:
    SmallestInfiniteSet() {
        for (int i = 1; i <= 1000; i++) {
            pq.push(i);
        }
        for (int i = 1; i <= 1000; i++) {
            v.push_back(i);
        }
    }
    
    int popSmallest() {
        int x = pq.top();
        pq.pop();
        auto it = find(v.cbegin(), v.cend(), x);
        v.erase(it);
        return x;
    }
    
    void addBack(int num) {
        auto it = find(v.cbegin(), v.cend(), num);
        if (it == v.cend()) {
            v.push_back(num);
            pq.push(num);
        }
    }
private:
    vector<int> v;
    priority_queue<int, vector<int>,greater<int>> pq;
};

/**
 * Your SmallestInfiniteSet object will be instantiated and called as such:
 * SmallestInfiniteSet* obj = new SmallestInfiniteSet();
 * int param_1 = obj->popSmallest();
 * obj->addBack(num);
 */

int main() {

  return 0;  
}
