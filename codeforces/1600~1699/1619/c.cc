#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

ll solve(ll a1, ll s1) {
  string a = to_string(a1), s = to_string(s1);
  int n = a.length(), m = s.length();
  string b;
  for (int i = n-1, j = m-1; i >= 0 || j >= 0; --i, --j) {
    if (j < 0) return -1;
    int aa = i < 0 ? 0 : (a[i] - '0'), sum = s[j] - '0';
    if (aa > sum) {
      if (j-1 < 0) return -1;
      sum += (s[--j] - '0') * 10;
      int diff = sum-aa;
      if (diff >= 10 || diff < 0) return -1;
      b.push_back(diff + '0');
    } else {
      b.push_back(sum-aa + '0');
    }
  }
  reverse(b.begin(), b.end());
  return stoll(b);
}

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(0);

  int t = 0;
  cin >> t;
  while (t-- > 0) {
    ll a = 0, s = 0;
    cin >> a >> s;
    ll ans = solve(a, s);
    cout << ans << '\n';
  }
  cout << flush;
  return 0;
}
