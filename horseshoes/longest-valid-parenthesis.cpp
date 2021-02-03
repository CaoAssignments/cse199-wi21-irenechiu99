class Solution {
public:
    int longestValidParentheses(string s) {
        //careful:: This is not a dp question :( 
        if (s.empty()) return 0;

        stack<int> store;
        int start = -1;
        int ans = 0;

        for (int i = 0; i < s.size(); i++) {
            if (s[i] == '(') store.push(i);
            else {
                if (store.empty()) start = i;
                else {
                    store.pop();
                    ans = max(ans, (store.empty()) ? i - start : i - store.top());
                }
            }
        }

        return ans;
    }
};