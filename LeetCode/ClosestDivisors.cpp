class Solution {
public:
    vector<int> closestDivisors(int num) {
        vector<long long> first;
        int x = num + 1;
        int square_root = static_cast<int>(sqrt(x)) + 1;
        for (int i = 1; i < square_root; i++) { 
            if (x % i == 0 && (i * i != x)) {
                first.push_back(i);
                first.push_back(x / i);
            }
            if (x % i == 0 && i*i == x) {
                first.push_back(i);
            }
        }
        
        vector<long long> second;
        x = num + 2;
        square_root = static_cast<int>(sqrt(x)) + 1;
        for (int i = 1; i < square_root; i++) { 
            if (x % i == 0 && (i * i != x)) {
                second.push_back(i);
                second.push_back(x / i);
            }
            if (x % i == 0 && i*i == x) {
                second.push_back(i);
            }
        }

        vector<pair<long long, vector<long long>>> v;
        for (decltype(first.size()) i = 0; i != first.size(); ++i) {
            for (decltype(first.size()) j = 0; j != first.size(); ++j) {
                if (first[i] * first[j] == num + 1 || first[i] * first[j] == num + 2) {
                    v.push_back({abs(first[i] - first[j]), {first[i], first[j]}});
                }
            }
        }
        for (decltype(second.size()) i = 0; i != second.size(); ++i) {
            for (decltype(second.size()) j = 0; j != second.size(); ++j) {
                if (second[i] * second[j] == num + 1 || second[i] * second[j] == num + 2)
                    v.push_back({abs(second[i] - second[j]), {second[i], second[j]}});
            }
        }
        
        sort(v.begin(), v.end(), 
             [=](const pair<long long, vector<long long>> &lhs, const pair<long long, vector<long long>> &rhs) {
                return lhs.first < rhs.first; 
             });
        
        vector<int> tmp((v.begin()->second).cbegin(), (v.begin()->second).cend());
        return tmp;
        
    }
};

int main() {
  
  
  return 0;  
}
