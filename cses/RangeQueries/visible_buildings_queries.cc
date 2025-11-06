#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

void solve() {
  int n = 0, q = 0;
  cin >> n >> q;
  vector<int> h(n);
  for (int i = 0; i < n; ++i) {
    cin >> h[i];
  }

  vector<int> next_taller(n+1, n);
  vector<int> st;
  for (int i = 0; i < n; ++i) {
    while (!st.empty() && h[i] > h[st.back()]) {
      next_taller[st.back()] = i;
      st.pop_back();
    }
    st.push_back(i);
  }

  int L = ceil(log2(n)) + 1;
  vector<vector<int>> binary_lift(L, vector<int>(n+1));
  binary_lift[0] = next_taller;
  for (int l = 1; l < L; ++l) {
    for (int i = 0; i <= n; ++i) {
      binary_lift[l][i] = binary_lift[l-1][binary_lift[l-1][i]];
    }
  }

  vector<int> ans;
  for (int i = 0; i < q; ++i) {
    int a = 0, b = 0;
    cin >> a >> b;
    a--;
    b--;
    int visible = 1;
    for (int l = L-1; l >= 0; --l) {
      if (binary_lift[l][a] <= b) {
        a = binary_lift[l][a];
        visible += (1<<l);
      }
    }
    ans.push_back(visible);
  }

  for (int visible : ans) {
    cout << visible << endl;
  }
}

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(0);

  solve();
  return 0;
}
