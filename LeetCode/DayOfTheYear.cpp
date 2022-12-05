class Solution {
public:
    int dayOfYear(string date) {
        auto pos = date.find('-', 0);
        string year(date.cbegin(), date.cbegin() + pos);
        auto prev = pos + 1;
        pos = date.find('-', pos + 1);
        string month(date.cbegin() + prev, date.cbegin() + pos);
        string day(date.cbegin() + pos + 1, date.cend());
        int year_ = stoi(year);
        int month_ = stoi(month);
        int day_ = stoi(day);
        vector<int> v = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
        if ((year_ % 400 == 0)) {
            v[1]++;
        } else if (year_ % 100 == 0) {
            
        } else if (year_ % 4 == 0) {
            ++v[1];
        }
        int answer = 0;
        int i = 0;
        while (i != month_ - 1) {
            answer += v[i];
            ++i;
        }
        return answer + day_;
    }
};

int main() {
  
  
  return 0;  
}
