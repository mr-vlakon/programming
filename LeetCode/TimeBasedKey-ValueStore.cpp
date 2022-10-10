class TimeMap {
public:
    TimeMap() {
        
    }
    
    void set(string key, string value, int timestamp) {
        um[timestamp].first = key;
        um[timestamp].second = value;
    }
    
    string get(string key, int timestamp) {
        auto it = --um.end();
        while (it != um.begin()) {
            if ((it->first <= timestamp) && (it->second.first == key)) {
                return it->second.second;
            }
            --it;
        }
        if ((it->first <= timestamp) && (it->second.first == key)) {
            return it->second.second;
        }
        
        
        return "";
    }
    
private:
    int timestampPrev = 0;
    map<int, pair<string, string>> um;
};

/**
 * Your TimeMap object will be instantiated and called as such:
 * TimeMap* obj = new TimeMap();
 * obj->set(key,value,timestamp);
 * string param_2 = obj->get(key,timestamp);
 */

int main() {
  
  
  
  return 0;  
}
