class Solution {
public:
    vector<int> lexicalOrder(int n) {
        vector<string> v;
        while (n) {
            v.push_back(to_string(n));
            --n;
        }
        sort(v.begin(), v.end());
        vector<int> result;
        for (const auto &e : v) {
            result.push_back(stoi(e));
        }
        return result;
    }
};

int main() {

  return 0;  
}
