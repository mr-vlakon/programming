class Solution {
public:
    bool haveConflict(vector<string>& event1, vector<string>& event2) {
        int xhb = stoi(string{event1[0].cbegin(), event1[0].cbegin() + 2});
        int xmb = stoi(string{event1[0].cbegin() + 3, event1[0].cend()});
 
        int xhe = stoi(string{event1[1].cbegin(), event1[1].cbegin() + 2});
        int xme = stoi(string{event1[1].cbegin() + 3, event1[1].cend()});
 
        
        int startx = xhb * 60 + xmb;
        int endx = xhe * 60 + xme;
        
        int yhb = stoi(string{event2[0].cbegin(), event2[0].cbegin() + 2});
        int ymb = stoi(string{event2[0].cbegin() + 3, event2[0].cend()});
 
        int yhe = stoi(string{event2[1].cbegin(), event2[1].cbegin() + 2});
        int yme = stoi(string{event2[1].cbegin() + 3, event2[1].cend()});
 
        int starty = yhb * 60 + ymb;
        int endy = yhe * 60 + yme;
        
        return !((startx < starty && endx < endy && starty > endx) || (startx > endy)); 
        
    }
};

int main() {
  
  
  
  return 0;  
}
