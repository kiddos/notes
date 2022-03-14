#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

ll solve(vector<int>& a, vector<int>& b) {
  int n = a.size();
  if (n == 1) return abs(a[0] - b[0]);

  ll edge1 = abs(a[0] - b[0]);
  ll edge2 = abs(a.back() - b.back());
  ll edge3 = abs(a[0] - b.back());
  ll edge4 = abs(a.back() - b[0]);

  auto alternative = [&](int a_index, int b_index) {
    int best_a_index = 0, best_b_index = 0;
    ll cost_a = numeric_limits<ll>::max();
    ll cost_b = numeric_limits<ll>::max();
    for (int i = 0; i < n; ++i) {
      if (i != b_index && abs(a[a_index] - b[i]) < cost_a) {
        cost_a = abs(a[a_index] - b[i]);
        best_a_index = i;
      }
      if (i != a_index && abs(b[b_index] - a[i]) < cost_b) {
        cost_b = abs(b[b_index] - a[i]);
        best_b_index = i;
      }
    }
    if (best_a_index == b_index && best_b_index == a_index) return cost_a;
    return cost_a + cost_b;
  };

  edge1 = min(edge1, alternative(0, 0));
  edge2 = min(edge2, alternative(n-1, n-1));
  // cout << "edge1: " << edge1 << ", edge2: " << edge2 << endl;

  edge3 = min(edge3, alternative(0, n-1));
  edge4 = min(edge4, alternative(n-1, 0));
  // cout << "edge3: " << edge3 << ", edge4: " << edge4 << endl;

  return min(edge1 + edge2, edge3 + edge4);
}

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(0);

  int t = 0;
  cin >> t;
  while (t-- > 0) {
    int n = 0;
    cin >> n;
    vector<int> a(n), b(n);
    for (int i = 0; i < n; ++i) cin >> a[i];
    for (int i = 0; i < n; ++i) cin >> b[i];

    ll ans = solve(a, b);
    cout << ans << '\n';
  }
  cout << flush;
  return 0;
}
