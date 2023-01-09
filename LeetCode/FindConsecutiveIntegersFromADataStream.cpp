class DataStream {
public:
    DataStream(int value, int k) : val_(value), k_(k) {
        
    }
    
    bool consec(int num) {
        if (num == val_) {
            ++temp;
        } else {
            temp = 0;
        }
        ++size;
        if (size < k_) {
            return false;
        }
        if (temp >= k_) {
            return true;
        } else {
            return false;
        }
    }
private:
    int size = 0;
    int temp = 0;
    int val_ = 0;
    int k_ = 0;
};

/**
 * Your DataStream object will be instantiated and called as such:
 * DataStream* obj = new DataStream(value, k);
 * bool param_1 = obj->consec(num);
 */

int main() {
  
  
  
  return 0;  
}
