class OrderedStream {
public:
    OrderedStream(int n) {
        v.resize(n);
    }
    
    vector<string> insert(int idKey, string value) {
        v[idKey - 1] = value;
        if ((idKey - 1) <= pointer) {
            rem = pointer;
            ++pointer;
            if (pointer < v.size() && v[pointer] != "") {
                while (pointer < v.size() && v[pointer] != "") {
                    ++pointer;
                }
            }
            return {v.begin() + rem, v.begin() + pointer};
        }
        return {};
    }
private:
    int rem = 0;
    int pointer = 0;
    vector<string> v;
};

/**
 * Your OrderedStream object will be instantiated and called as such:
 * OrderedStream* obj = new OrderedStream(n);
 * vector<string> param_1 = obj->insert(idKey,value);
 */

int main() {
  
  
  return 0;  
}
