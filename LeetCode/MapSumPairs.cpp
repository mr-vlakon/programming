class MapSum {
public:
    MapSum() {
        
    }
    
    void insert(string key, int val) {
        um[key] = val;
    }
    
    bool isPrefix(const string &prefix, const string &curr) {
        auto it = std::mismatch(prefix.begin(), prefix.end(), curr.begin());
        if (it.first == prefix.end()) {
            return true;
        }
        return false;
    }
    int sum(string prefix) {
        int ans = 0;
        for (const auto &e: um) {
            if (isPrefix(prefix, e.first))
                ans += e.second;
        }
        return ans;
    }
private:
    unordered_map<string, int> um;
};

/**
 * Your MapSum object will be instantiated and called as such:
 * MapSum* obj = new MapSum();
 * obj->insert(key,val);
 * int param_2 = obj->sum(prefix);
 */

int main() {
 
  
  
  return 0;  
}
