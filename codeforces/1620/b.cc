#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

ll solve(ll w, ll h, vector<int>& x1, vector<int>& x2, vector<int>& y1, vector<int>& y2) {
  ll area1 = (x1.back() - x1[0]) * h;
  ll area2 = (x2.back() - x2[0]) * h;
  ll area3 = (y1.back() - y1[0]) * w;
  ll area4 = (y2.back() - y2[0]) * w;
  return max({area1, area2, area3, area4});
}

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(0);

  int t = 0;
  cin >> t;
  while (t-- > 0) {
    int w = 0, h = 0;
    cin >> w >> h;

    int k = 0;
    cin >> k;
    vector<int> x1(k);
    for (int i = 0; i < k; ++i) cin >> x1[i];

    cin >> k;
    vector<int> x2(k);
    for (int i = 0; i < k; ++i) cin >> x2[i];

    cin >> k;
    vector<int> y1(k);
    for (int i = 0; i < k; ++i) cin >> y1[i];

    cin >> k;
    vector<int> y2(k);
    for (int i = 0; i < k; ++i) cin >> y2[i];

    ll ans = solve(w, h, x1, x2, y1, y2);
    cout << ans << '\n';
  }
  cout << flush;
  return 0;
}
