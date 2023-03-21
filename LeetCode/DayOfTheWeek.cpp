class Solution {
public:
    bool isLeap(const int &x) {
        if (x % 400 == 0) {
            return true;
        }
        if (x % 100 == 0)
            return false;
        if (x % 4 == 0) {
            return true;
        }
        return false;
    }
    string dayOfTheWeek(int day, int month, int year) {
        vector<int> months{31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
        vector<int> monthsV{31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};        
        int di1 = 1;
        int yi1 = 1971;
        int mi1 = 1;
        int start = 4;
 
        int di2 = day;
        int yi2 = year;
        int mi2 = month;
        int cnt = 0;
        while (di1 != di2 || mi1 != mi2 || yi1 != yi2) {
                if (!isLeap(yi1) && months[mi1 - 1] > di1) {
                    ++di1;
                    if (start == 7) {
                        start = 1;
                    } else {
                        ++start;
                    }                 
                    ++cnt;
                } else if(isLeap(yi1) && monthsV[mi1 - 1] > di1) {
                    ++di1;
                    if (start == 7) {
                        start = 1;
                    } else {
                        ++start;
                    }
                    ++cnt;
                } else if (!isLeap(yi1) && months[mi1 - 1] == di1) {
                    if (start == 7) {
                        start = 1;
                    } else {
                        start++;
                    }
                    di1 = 1;
                    ++cnt;
                    mi1++;
                    if (mi1 == 13) {
                        mi1 = 1;
                        yi1++;
                    }
                } else if (isLeap(yi1) && monthsV[mi1 - 1] == di1) {
                    if (start == 7) {
                        start = 1;
                    } else {
                        start++;
                    }
                    di1 = 1;
                    ++cnt;
                    mi1++;
                    if (mi1 == 13) {
                        mi1 = 1;
                        yi1++;
                    }
                }            
        }
        vector<string> v{"Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday", "Sunday"};
        return v[start % 7];
    }
};

int main() {
  
  
  return 0;  
}
