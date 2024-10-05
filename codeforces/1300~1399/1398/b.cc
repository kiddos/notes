#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

void solve() {
  string s;
  cin >> s;
  int n = s.length();
  int i = 0;
  vector<int> lengths;
  while (i < n) {
    if (s[i] == '0') {
      i++;
    } else {
      int j = i;
      while (j < n && s[j] == '1') {
        j++;
      }
      lengths.push_back(j - i);
      i = j;
    }
  }
  sort(lengths.rbegin(), lengths.rend());
  int alice = 0;
  for (int i = 0; i < (int)lengths.size(); i += 2) {
    alice += lengths[i];
  }
  cout << alice << endl;
}

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(0);

  int T = 0;
  cin >> T;
  for (int t = 0; t < T; ++t) {
    solve();
  }
  return 0;
}
