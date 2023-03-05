class Solution {
public:
    int passThePillow(int n, int time) {
        int start = 1;
        bool direction = true;
        while (time) {
            if (start == n && direction) {
                direction = false; 
                --start;
            } else if (direction) {
                ++start;
            } else if (!direction && start == 1) {
                ++start;
                direction = true;
            } else if (!direction) {
                --start;
            }
            --time;
        }
        return start;
        
        
    }
};

int main() {
  
  
  
  return 0;  
}
