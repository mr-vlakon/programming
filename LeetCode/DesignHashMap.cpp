class MyHashMap {
public:
    MyHashMap() {
        
    }
    
    void put(int key, int value) {
        um[key] = value;
    }
    
    int get(int key) {
        auto it = um.find(key);
        if (it == um.cend()) {
            return -1;
        } else
            return um[key];
    }
    
    void remove(int key) {
        um.erase(key);
    }
private:
    unordered_map<int ,int> um;
};

/**
 * Your MyHashMap object will be instantiated and called as such:
 * MyHashMap* obj = new MyHashMap();
 * obj->put(key,value);
 * int param_2 = obj->get(key);
 * obj->remove(key);
 */

int main() {
  
  
  return 0;  
}
