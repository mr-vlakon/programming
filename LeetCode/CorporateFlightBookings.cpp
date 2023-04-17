class Solution {
public:
    vector<int> corpFlightBookings(vector<vector<int>>& bookings, int n) {
        vector<int> flights(n, 0);
        for (const auto &e: bookings) {
            flights[e[1] - 1] += e[2];
            if ((e[0] - 2) >= 0) {
                flights[e[0] - 2] -= e[2];
            }
        }
        vector<int> pref(flights.size(), 0);
        int tmp = 0;
        int start = flights.size() - 1;
        for ( ;start >= 0; --start) {
            tmp += flights[start];
            pref[start] = tmp;
        }
        return pref;
    }
};

int main() {
  
  
  
  return 0;  
}
