#include <bits/stdc++.h>

using namespace std;

using ll = long long;

struct Segment {
  ll l, r;
};

struct CompareSegment {
  bool operator()(const Segment& s1, const Segment& s2) {
    return (s1.r - s1.l) < (s2.r - s2.l);
  }
};

void solve() {
  ll n = 0, m = 0;
  cin >> n >> m;

  vector<ll> a(m);
  for (int i = 0; i < m; ++i) cin >> a[i];

  sort(a.begin(), a.end());
  priority_queue<Segment, vector<Segment>, CompareSegment> pq;
  for (int i = 1; i < m; ++i) {
    if (a[i-1] != a[i]-1) {
      pq.push(Segment{a[i-1]+1, a[i]-1});
    }
  }
  if (a.back() != n || a[0] != 1) {
    pq.push(Segment{a.back()+1, a[0] + n - 1});
  }

  ll protect = 0;
  int day = 0;
  while (!pq.empty()) {
    auto [l, r] = pq.top();
    // cout << "protect: " << l << ", " << r << endl;
    pq.pop();
    ll l2 = l + day, r2 = r - day;
    if (l2 <= r2) {
      if (r2 == l2) {
        protect++;
      } else {
        protect += r2 - l2;
      }
    }
    day += 2;
  }

  ll ans = n - protect;
  cout << ans << endl;
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
