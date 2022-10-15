class Solution {
public:
    int countTime(string time) {
        int f = 1;
        int s = 1;
        int t = 1;
        int four = 1;
        int fs = 0;
   
        if (time[0] == '?' && (time[1] <= '3' || time[1] == '?')) {
            f = 3;
        } else if (time[0] == '?' && time[1] >= '4') {
            f = 2;
        }
        
        if (time[1] == '?' && time[0] == '?') {
            fs = 24;
        } else if (time[1] == '?' && (time[0] == '2')) {
            s = 4;
        } else if (time[1] == '?' && (time[0] == '1' || time[0] == '0')) {
            s = 10;
        }
                
        if (time[3] == '?') {
            t = 6;
        } 
            
        if (time[4] == '?') {
            four = 10;
        }
        
        if (fs != 0) {
            return fs * t * four;
        } else
            return f * s * t * four;
    }
};

int main() {
  
  
  return 0;  
}
