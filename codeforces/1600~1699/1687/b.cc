#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

i64 query(const string& s) {
  cout << "? " << s << endl;
  i64 L = 0;
  cin >> L;
  return L;
}

void answer(int L) {
  cout << "! " << L << endl;
}

void solve() {
  int n = 0, m = 0;
  cin >> n >> m;

  vector<i64> length(m+1);
  for (int i = 1; i <= m; ++i) {
    string s = string(m, '0');
    s[i-1] = '1';
    length[i] = query(s);
  }

  vector<pair<i64,int>> tracks;
  for (int i = 1; i <= m; ++i) {
    tracks.push_back({length[i], i});
  }

  sort(tracks.begin(), tracks.end());

  string s(m, '0');
  i64 ans = 0;
  for (int i = 0; i < m; ++i) {
    int idx = tracks[i].second - 1;
    s[idx] = '1' ;
    i64 value = query(s);
    if (value == ans + tracks[i].first) {
      ans = value;
    } else {
      s[idx] = '0';
    }
  }

  answer(ans);
}

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(0);

  solve();
  return 0;
}
