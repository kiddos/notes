#include <bits/stdc++.h>

using namespace std;

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(0);

  int T = 0;
  cin >> T;
  for (int t = 0; t < T; ++t) {
    int n = 0;
    cin >> n;
    string s;
    cin >> s;
    unordered_map<char, int> right;
    for (char ch : s) {
      right[ch]++;
    }

    int ans = 0;
    unordered_map<char, int> left;
    for (char ch : s) {
      right[ch]--;
      if (right[ch] == 0) right.erase(ch);
      left[ch]++;

      if (right.size() > 0) {
        ans = max(ans, (int)left.size() + (int)right.size());
      }
    }
    cout << ans << endl;
  }
  return 0;
}
