class Solution {
public:
    bool lemonadeChange(vector<int>& bills) {
        unordered_map<int, int> um;
        for (const auto &e: bills) {
            if (e > 5) {
                int tmp = e;
                if (e == 20) {
                    if (um[10] != 0) {
                        --um[10];
                        if (um[5] != 0) {
                            --um[5];
                        } else {
                            return false;
                        }
                    } else {
                        if (um[5] < 3) {
                            return false;
                        } else {
                            um[5] -= 3;
                        }
                    }
                } else if (e == 10) {
                    if (um[5] != 0) {
                        --um[5];
                    } else {
                        return false;
                    }
                }
            } 
            um[e]++;
        }
        return true;
    }
};

int main() {
  
  
  
  return 0;  
}
