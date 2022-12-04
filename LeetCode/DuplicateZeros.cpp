class Solution {
public:
    void duplicateZeros(vector<int>& arr) {
        vector<int> v;
        for (const auto &e: arr) {
            if (e != 0) {
                v.push_back(e);
            } else {
                v.push_back(e);
                v.push_back(e);
            }
        }
        int initialSize = arr.size();
        arr = v;
        arr.resize(initialSize);
    }
};

int main() {
  
  
  return 0;  
}
