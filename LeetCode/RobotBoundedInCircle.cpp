class Solution {
public:
    bool isRobotBounded(string instructions) {
        int startR = 0;
        int startC = 0;
        int direction = 0;
        int i = 0;
        while (i < 4) {
            for (const auto &e: instructions) {
                if (e == 'G') {
                    if (direction == 0) {
                        ++startR;
                    } else if (direction == 1) {
                        --startR;    
                    } else if (direction == 2) {
                        ++startC;
                    } else {
                        --startC;
                    }
                } else {
                    if (direction == 0) {
                        if (e == 'L') {
                            direction = 3;
                        } else {
                            direction = 2;
                        }
                    } else if (direction == 1) {
                        if (e == 'L') {
                            direction = 2;
                        } else {
                            direction = 3;
                        }
                    } else if (direction == 2) {
                        if (e == 'L') {
                            direction = 0;
                        } else {
                            direction = 1;
                        }
                    } else {
                        if (e == 'L') {
                            direction = 1;
                        }  else {
                            direction = 0;
                        }
                    }
                }                
            }
            if (startC == 0 && startR == 0) return true;
            ++i;
        }
        if (startC == 0 && startR == 0) return true;
        return false;
    }
};

int main() {
  
  
  
  
  return 0;  
}
