class FrequencyTracker {
public:
    FrequencyTracker() {
        v.resize(100003, 0);
    }
    
    void add(int number) {
        v[um[number] + 1] += um[number] + 1;
        um[number]++;
        if (um[number] != 1) {
            v[um[number] - 1] -= um[number] - 1;
        } 
    }
    
    void deleteOne(int number) {
        it = um.find(number);
        if (it != um.cend()) {
            tmp = um[number];
            v[um[number]] -= um[number];
            v[um[number] - 1] += um[number] - 1;
            um.erase(it);
            if (tmp > 1)
            um[number] = tmp - 1;
        }
    }
    
    bool hasFrequency(int frequency) {
        return v[frequency] > 0;
    }
private:
    int tmp = 0;
    vector<int> v;
    unordered_map<int, int>::iterator it;
    unordered_map<int, int> um;
};

/**
 * Your FrequencyTracker object will be instantiated and called as such:
 * FrequencyTracker* obj = new FrequencyTracker();
 * obj->add(number);
 * obj->deleteOne(number);
 * bool param_3 = obj->hasFrequency(frequency);
 */

int main() {
  
  
  return 0;  
}
