class RLEIterator {
public:
    RLEIterator(vector<int>& encoding) : encoded(encoding) {
        
    }
    
    int next(int n) {
        if (pos >= encoded.size()) return -1;
        remain = -1;
        while (n && pos < encoded.size()) {
            if (encoded[pos] > n) {
                encoded[pos] -= n;
                n = 0;
                remain = encoded[pos + 1];
                break;
            } else if (encoded[pos] == n) {
                n = 0;
                encoded[pos] = 0;
                remain = encoded[pos + 1];
            } else {
                n -= encoded[pos];
                encoded[pos] = 0;
            }
            pos += 2;
        }
        return remain;
    }
private:
    int remain = 0;
    int pos = 0;
    vector<int> encoded;
};

/**
 * Your RLEIterator object will be instantiated and called as such:
 * RLEIterator* obj = new RLEIterator(encoding);
 * int param_1 = obj->next(n);
 */

int main() {
  
  
  
  
  return 0;  
}
