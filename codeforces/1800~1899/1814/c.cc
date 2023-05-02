#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

ll compute_time(const vector<int>& a, const vector<int>& b, const vector<ll>& r, ll s1, ll s2) {
  ll t = 0;
  for (int i = 0; i < a.size(); ++i) {
    t += r[a[i]-1] * s1 * (i+1);
  }
  for (int i = 0; i < b.size(); ++i) {
    t += r[b[i]-1] * s2 * (i+1);
  }
  return t;
}

void solve() {
  int n = 0, s1 = 0, s2 = 0;
  cin >> n >> s1 >> s2;
  vector<ll> r(n);
  for (int i = 0; i < n; ++i) cin >> r[i];

  vector<int> index(n);
  iota(index.begin(), index.end(), 0);
  sort(index.begin(), index.end(), [&](int i1, int i2) {
    return r[i1] > r[i2];
  });

  vector<int> a, b;
  for (int idx : index) {
    ll add_to_a = r[idx] * s1 * (a.size()+1);
    ll add_to_b = r[idx] * s2 * (b.size()+1);
    if (add_to_a < add_to_b) {
      a.push_back(idx+1);
    } else if (add_to_b < add_to_a) {
      b.push_back(idx+1);
    } else {
      if (s1 < s2) {
        a.push_back(idx+1);
      } else {
        b.push_back(idx+1);
      }
    }
  }

  cout << a.size();
  for (int aa : a) cout << " " << aa;
  cout << endl;
  cout << b.size();
  for (int bb : b) cout << " " << bb;
  cout << endl;

  // cout << "sum: " << compute_time(a, b, r, s1, s2) << endl;
  // cout << "sum: " << compute_time({5, 6}, {1, 7, 2, 4, 3}, r, s1, s2) << endl;
  // cout << "sum: " << compute_time({4, 2, 7, 5}, {6, 3, 1, 8}, r, s1, s2) << endl;
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
