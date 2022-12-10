class Solution {
public:
    int maximumValue(vector<string>& strs) {
        int max = 0;
        for (const auto &e: strs) {
            auto it = e.find_first_not_of("0123456789");
            if (it == string::npos) {
                int tmp = stoi(e);
                if (max < tmp)
                    max = tmp;
            } else {
                if (max < e.size())
                    max = e.size();
            }
        }
        return max;
    }
};

int main() {
  
  
  
  return 0;  
}
