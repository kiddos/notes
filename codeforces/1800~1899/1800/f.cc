#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(0);

  int n = 0;
  cin >> n;

  vector<pair<int,int>> repr;
  for (int i = 0; i < n; ++i) {
    pair<int,int> r;
    string s;
    cin >> s;
    for (char ch : s) {
      int c = ch - 'a';
      r.first |= (1<<c);
      r.second ^= (1<<c);
    }
    repr.push_back(r);
  }

  int FULL = (1<< 26) - 1;

  ll ans = 0;
  for (int c = 0; c < 26; ++c) {
    int mask = FULL ^ (1<<c);
    unordered_map<int, int> prefix;
    for (int i = 0; i < n; ++i) {
      if (!(repr[i].first & (1<<c))) {
        ll target = mask ^ repr[i].second;
        if (prefix.count(target)) {
          ans += prefix[target];
        }
        prefix[repr[i].second]++;
      }
    }
  }
  cout << ans << endl;
  return 0;
}
