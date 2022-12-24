class Solution {
public:
    int captureForts(vector<int>& forts) {
        int max = 0;
        for (int i = 0; i != forts.size(); ++i) {
            if (forts[i] == 1) {
            int tmp = 0;
            bool status = false;
            for (int j = i + 1; j != forts.size(); ++j) {
                if (forts[j] == 0) {
                    ++tmp;
                } else if (forts[j] == -1) {
                    status = true;
                    break;
                } else if (forts[j] == 1) {
                    break;
                }
            }
            if (status) {
                if (tmp > max)
                    max = tmp;
            }
            status = false;
            tmp = 0;
            for (int j = i - 1; j >= 0; --j) {
                if (forts[j] == 0) {
                    ++tmp;
                } else if (forts[j] == -1) {
                    status = true;
                    break;
                } else if (forts[j] == 1) {
                    break;
                }
            }
            if (status) {
                if (tmp > max) {
                    max = tmp;
                }
            }
            }
        }
        
        return max;
    }
};

int main() {
  
  
  
  
  return 0;  
}
