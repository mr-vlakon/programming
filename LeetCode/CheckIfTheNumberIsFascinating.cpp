class Solution {
public:
    bool isFascinating(int n) {
        string result = to_string(n) + to_string(2*n) + to_string(3*n);
        vector<int> v(10, 0);
        for (const auto &e: result) {
            ++v[e - '0'];
        }
        if (v[0] != 0) return false;
        for (int i = 1; i != v.size(); ++i) {
            if (v[i] != 1) return false;
        }
        return true;
    }
};
/*
class Solution {
public:
    bool isFascinating(int n) {
        string first = to_string(n);
        string second = to_string(2*n);
        string third = to_string(3*n);
        string result = first + second + third;
        vector<int> v(10, 0);
        for (const auto &e: result) {
            ++v[e - '0'];
        }
        if (v[0] != 0) return false;
        for (int i = 1; i != v.size(); ++i) {
            if (v[i] != 1) return false;
        }
        return true;
    }
};
*/

int main() {
  
  
  return 0;  
}
