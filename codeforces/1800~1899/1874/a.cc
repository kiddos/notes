#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

void solve() {
  int n = 0, m = 0, k = 0;
  cin >> n >> m >> k;
  vector<int> a(n);
  for (int i = 0; i < n; ++i) cin >> a[i];
  vector<int> b(m);
  for (int i = 0; i < m; ++i) cin >> b[i];

  multiset<int> c(a.begin(), a.end());
  multiset<int> d(b.begin(), b.end());
  i64 A = accumulate(a.begin(), a.end(), 0LL);
  i64 B = accumulate(b.begin(), b.end(), 0LL);

  array<i64, 3> start = {A, B, 0};
  vector<array<i64, 3>> seq = {start};
  map<array<i64,3>, int> found;
  found[start] = 0;

  int cycle_len = -1;
  int init = -1;
  for (int i = 1; i <= k; ++i) {
    if (i % 2 == 1) {
      int smallest = *c.begin();
      int largest = *d.rbegin();
      if (smallest < largest) {
        A -= smallest;
        A += largest;
        B -= largest;
        B += smallest;

        c.erase(c.begin());
        c.insert(largest);
        d.erase(prev(d.end()));
        d.insert(smallest);
      }
    } else {
      int smallest = *d.begin();
      int largest = *c.rbegin();
      if (smallest < largest) {
        B -= smallest;
        B += largest;
        A -= largest;
        A += smallest;

        c.erase(prev(c.end()));
        d.erase(d.begin());
        c.insert(smallest);
        d.insert(largest);
      }
    }

    array<i64,3> key = {A, B, i % 2};
    if (found.count(key)) {
      init = found[key];
      cycle_len = i - found[key];
      break;
    }
    found[key] = i;
    seq.push_back({A, B, i % 2});
  }

  //for (auto& [A, B, turn] : seq) {
    //cout << "(" << A << "," << B << "," << turn << ")  ";
  //}
  //cout << endl;

  if (cycle_len < 0) {
    array<i64, 3> ans = seq.back();
    cout << ans[0] << endl;
  } else {
    //cout << "cycle len=" << cycle_len << endl;
    //cout << "init=" << init << endl;
    int offset = (k-init) % cycle_len;
    array<i64, 3> ans = seq[init + offset];
    cout << ans[0] << endl;
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
