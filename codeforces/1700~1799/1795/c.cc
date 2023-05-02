#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

void solve() {
  int n = 0;
  cin >> n;
  vector<ll> a(n);
  for (int i = 0; i < n; ++i) cin >> a[i];
  vector<ll> b(n);
  for (int i = 0; i < n; ++i) cin >> b[i];

  vector<ll> prefix = {0};
  for (int i = 0; i < n; ++i) {
    prefix.push_back(b[i] + prefix.back());
  }

  vector<ll> line(n+1);
  vector<ll> extra(n);
  for (int i = 0; i < n; ++i) {
    int l = i, r = n-1;
    int index = -1;
    while (l <= r) {
      int mid = l + (r-l) / 2;
      ll sum = prefix[mid+1] - prefix[i];
      if (sum <= a[i]) {
        l = mid+1;
        index = mid;
      } else {
        r = mid-1;
      }
    }

    if (index >= 0) {
      line[index+1] --;
      line[i]++;
      ll sum = prefix[index+1] - prefix[i];
      ll left_over = a[i] - sum;
      // cout << "add 1 to " << i << " - " << index 
      //   << ", left over: " << left_over << endl;
      if (index+1 < n) {
        extra[index+1] += left_over;
      }
    } else {
      extra[i] += a[i];
    }
  }

  vector<ll> ans(n);

  for (int i = 1; i <= n; ++i) {
    line[i] += line[i-1];
  }
  // cout << "line: " << endl;
  // for (int i = 0; i <= n; ++i) {
  //   cout << line[i] << " ";
  // }
  // cout << endl;

  for (int i = 0; i < n; ++i) {
    ll prefix_sum = line[i];
    ans[i % n] += prefix_sum * b[i % n];
  }
  for (int i = 0; i < n; ++i) {
    ans[i] += extra[i];
  }

  for (int i = 0; i < n; ++i) {
    cout << ans[i] << " ";
  }
  cout << endl;
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
