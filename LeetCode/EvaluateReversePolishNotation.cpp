class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> st;
        int answer = 0;
        int first = 0;
        int second = 0;
        for (int i = 0; i != tokens.size(); ++i) {
            if (tokens[i] != "+" && tokens[i] != "-" && tokens[i] != "*" 
            && tokens[i] != "/") {
                st.push(stoi(tokens[i]));
            } else {
                first = st.top();
                st.pop();
                second = st.top();
                st.pop();
                switch(tokens[i][0]) {
                    case '+': {
                        answer = first + second;
                        st.push(answer);
                        break;
                    }
                    case '-': {
                        answer = second - first;
                        st.push(answer);
                        break;
                    }
                    case '*': {
                        answer = first * second;
                        st.push(answer);
                        break;
                    }
                    case '/': {
                        answer = second / first;
                        st.push(answer);
                        break;
                    }
                    default: {
                        break;
                    }
                }
            }
        }
        return (st.size() == 0) ? answer : st.top();    
    }
};

int main() {
  
  
  
  
  return 0;  
}
