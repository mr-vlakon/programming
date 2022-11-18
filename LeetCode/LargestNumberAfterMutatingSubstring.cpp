class Solution {
public:
    string maximumNumber(string num, vector<int>& change) {
        bool prev = false;
        for (auto &e: num) {
            if ((e - '0' < change[e - '0'] ) || 
                (e - '0' == change[e - '0'] && prev))
            {
                prev = true;
                e = change[e - '0'] + '0';
            } else {
                if (prev == true) {
                    break;
                }
            }
        }
        return num;
    }
};

int main() {
  
  
  
  return 0;  
}
