class RecentCounter {
public:
    RecentCounter() {
        
    }
    
    int ping(int t) {
        s.insert(t);
        int x = t - 3000;
        auto it = s.lower_bound(x);
        return vector<int>{it, s.cend()}.size();
    }
private:
    set<int> s;
};

/**
 * Your RecentCounter object will be instantiated and called as such:
 * RecentCounter* obj = new RecentCounter();
 * int param_1 = obj->ping(t);
 */

int main() {
  
  
  return 0;  
}
