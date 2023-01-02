#include <bits/stdc++.h>

using namespace std;

string solve(vector<string>& bigrams) {
  int n = bigrams.size();
  string ans = bigrams[0];
  bool found_missing = false;
  for (int i = 1; i < n; ++i) {
    if (bigrams[i][0] != ans.back()) {
      ans += bigrams[i];
      found_missing = true;
    } else {
      ans.push_back(bigrams[i][1]);
    }
  }
  if (!found_missing) {
    ans.push_back('a');
  }
  return ans;
}

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(0);

  int t = 0;
  cin >> t;
  while (t-- > 0) {
    int n = 0;
    cin >> n;
    vector<string> bigrams(n-2);
    for (int i = 0; i < n-2; ++i) cin >> bigrams[i];
    string ans = solve(bigrams);
    cout << ans << '\n';
  }
  cout << flush;
  return 0;
}
