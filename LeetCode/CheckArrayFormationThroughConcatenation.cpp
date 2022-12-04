class Solution {
public:
    bool canFormArray(vector<int>& arr, vector<vector<int>>& pieces) {
        int i = 0;
        while (i < arr.size()) {
            auto it = find_if(pieces.cbegin(), pieces.cend(), [=](const vector<int> &x) {
                return x[0] == arr[i];    
            });
            if (it == pieces.cend()) {
                return false;
            }
            for (const auto &e: *it) {
                if (arr[i] != e) {
                    return false;    
                }
                ++i;
            }   
        }
        return true;
    }
};

int main() {
  
  
  return 0;  
}
