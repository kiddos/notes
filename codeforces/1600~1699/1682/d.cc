#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

void solve() {
  int n = 0;
  cin >> n;
  string s;
  cin >> s;

  int one = count(s.begin(), s.end(), '1');

  if (one > 0 && one % 2 == 0) {
    cout << "YES" << endl;
  } else {
    cout << "NO" << endl;
    return;
  }

  vector<pair<int,int>> edges;

  // if a node has odd degree (eg. s[i] == 1)
  // it should always be able to connect to the previous node
  // so find such a node and imagine it to be the root
  //
  // for all other nodes,
  // if s[i] == 1, it should connect the previous node to the root
  // else, else it should connect to the next node
  int p = s.find('1');
  p = (p-1+n) % n;
  for (int i = 1; i < n; ++i) {
    int a = (p+i) % n;
    int b = (p+i+1) % n;
    if (s[b] == '0') {
      edges.emplace_back(a+1, b+1);
    } else {
      edges.emplace_back(a+1, p+1);
    }
  }

  for (auto& [u, v] : edges) {
    cout << u << " " << v << endl;
  }
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
