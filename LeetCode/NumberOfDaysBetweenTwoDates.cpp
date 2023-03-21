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
    int daysBetweenDates(string date1, string date2) {
        vector<int> months{31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
        vector<int> monthsV{31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};        
        int month = 1;
        int day = 1;
        int year = 1971;
        string d1 = date1;
        string year1;
        int i = 0;
        for (; i != date1.size(); ++i) {
            if (date1[i] == '-') {
                break;
            }
            year1.push_back(date1[i]);
        }
        ++i;
        string month1;
        for (; i != date1.size(); ++i) {
            if (date1[i] == '-') {
                break;
            }
            month1.push_back(date1[i]);
        }
        ++i;
        string day1;
        for (; i != date1.size(); ++i) {
            day1.push_back(date1[i]);
        }
        int di1 = stoi(day1);
        int yi1 = stoi(year1);
        int mi1 = stoi(month1);
        year1.resize(0);
        i = 0;
        for (; i != date2.size(); ++i) {
            if (date2[i] == '-') {
                break;
            }
            year1.push_back(date2[i]);
        }
        ++i;
        month1.resize(0);
        for (; i != date2.size(); ++i) {
            if (date2[i] == '-') {
                break;
            }
            month1.push_back(date2[i]);
        }
        ++i;
        day1.resize(0);
        for (; i != date2.size(); ++i) {
            day1.push_back(date2[i]);
        }
        int di2 = stoi(day1);
        int yi2 = stoi(year1);
        int mi2 = stoi(month1);
        int cnt = 0;
        if (date1 < date2) {
            while (di1 != di2 || mi1 != mi2 || yi1 != yi2) {
                if (!isLeap(yi1) && months[mi1 - 1] > di1) {
                    ++di1;
                    ++cnt;
                } else if(isLeap(yi1) && monthsV[mi1 - 1] > di1) {
                    ++di1;
                    ++cnt;
                } else if (!isLeap(yi1) && months[mi1 - 1] == di1) {
                    di1 = 1;
                    ++cnt;
                    mi1++;
                    if (mi1 == 13) {
                        mi1 = 1;
                        yi1++;
                    }
                } else if (isLeap(yi1) && monthsV[mi1 - 1] == di1) {
                    di1 = 1;
                    ++cnt;
                    mi1++;
                    if (mi1 == 13) {
                        mi1 = 1;
                        yi1++;
                    }
                }            }
        } else {
            while (di1 != di2 || mi1 != mi2 || yi1 != yi2) {
                if (!isLeap(yi2) && months[mi2 - 1] > di2) {
                    ++di2;
                    ++cnt;
                } else if(isLeap(yi2) && monthsV[mi2 - 1] > di2) {
                    ++di2;
                    ++cnt;
                } else if (!isLeap(yi2) && months[mi2 - 1] == di2) {
                    di2 = 1;
                    ++cnt;
                    mi2++;
                    if (mi2 == 13) {
                        mi2 = 1;
                        yi2++;
                    }
                } else if (isLeap(yi2) && monthsV[mi2 - 1] == di2) {
                    di2 = 1;
                    ++cnt;
                    mi2++;
                    if (mi2 == 13) {
                        mi2 = 1;
                        yi2++;
                    }
                }
            }
        }
        return cnt;
    }
};

int main() {
  
  
  return 0;  
}

