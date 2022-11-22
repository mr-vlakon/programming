class Solution {
public:
    string reformatDate(string date) {
        vector<string> months = {"Jan", "Feb", "Mar", "Apr", "May", "Jun", "Jul", "Aug", "Sep", "Oct", "Nov", "Dec"};
        istringstream is(date);
        string day;
        string result;
        is >> day;
        auto pos = day.find_first_not_of("0123456789");
        string d = string{day.cbegin(), day.cbegin() + pos};
        string month;
        is >> month;
        auto it = find(months.cbegin(), months.cend(), month);
        string m = to_string(it - months.cbegin() + 1);
        if (m.size() == 1) {
            m.insert(m.cbegin(), '0');
        }
        if (d.size() == 1) {
            d.insert(d.cbegin(), '0');
        }
        string year;
        is >> year;
        return year + "-" + m + "-" + d;  
    }
};

int main() {
  
  
  
  return 0;  
}
