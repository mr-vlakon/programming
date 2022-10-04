class Solution {
public:
    vector<int> decode(vector<int>& encoded, int first) {
        int prev = first;
        vector<int> res{first};
        for (decltype(encoded.size()) i = 0; i != encoded.size(); ++i) {
            prev = encoded[i]^prev;
            res.push_back(prev);            
        }
        return res;
    }
};

int main() {
  
  
  return 0;  
}
