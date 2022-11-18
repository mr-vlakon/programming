class Solution {
public:
    string maximumNumber(string num, vector<int>& change) {
        unordered_map<int, int> um;
        int i = 0;
        for (const auto &e: change) {
            um[i] = e;
            ++i;
        }
        bool status = false;
        bool prev = false;
        for (auto &e: num) {
            if ((e - '0' < um[e - '0'] && !status) || 
                (e - '0' == um[e - '0'] && prev))
            {
                prev = true;
                e = um[e - '0'] + '0';
            } else {
                if (prev == true) {
                    status = true;
                }
            }
        }
        return num;
    }
};

int main() {
  
  
  
  return 0;  
}
