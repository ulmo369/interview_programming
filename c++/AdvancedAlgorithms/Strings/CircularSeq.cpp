#include <bits/stdc++.h>

using namespace std;

int main() {

    string s, t;
    string ans = "Z";
    int T;
    cin >> T;

    while (T--) {

        ans = "Z";
        cin >> s;
        int len = s.size();
        s = " " + s + s;

        for (int i = 1; i <= len; i++) {
            t = s.substr(i, len);
            ans = min(ans, t);
        }
        cout << ans << endl;
    }
    return 0;
}