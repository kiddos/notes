#include <bits/stdc++.h>

using namespace std;

vector<int> query(int& n, vector<int>& remove) {
  cout << "- " << remove.size() << " ";
  for (int r : remove) cout << r << " ";
  cout << endl;

  vector<int> remain;
  for (int i = 0; i < n-remove.size(); ++i) {
    int type = 0;
    cin >> type;
    remain.push_back(type);
  }
  n -= remove.size();
  remove.clear();
  return remain;
}

void answer(int x) {
  cout << "! " << x << endl;
}

void solve() {
  int n = 0;
  cin >> n;
  vector<int> a(n);
  for (int i = 0; i < n; ++i) cin >> a[i];


  int target_type = 0;
  auto has_change = [&](vector<int>& a1, vector<int>& a2) {
    vector<int> count(10);
    for (int a : a1) count[a]++;
    for (int a : a2) count[a]--;
    for (int i = 1; i <= 9; ++i) {
      if (count[i] > 0) {
        target_type = i;
        return true;
      }
    }
    return false;
  };

  vector<int> remove;
  // stage1:
  // let mimic change from c1 -> c2
  // and keep all c2
  vector<int> stage1 = query(n, remove);
  if (!has_change(stage1, a)) {
    stage1 = query(n, remove);
    has_change(stage1, a);
  }

  vector<int> temp;
  for (int i = 0; i < n; ++i) {
    if (stage1[i] != target_type) {
      remove.push_back(i+1);
    } else {
      temp.push_back(stage1[i]);
    }
  }
  stage1 = temp;

  // cout << "target_type: " << target_type << endl;

  vector<int> stage2 = query(n, remove);
  if (!has_change(stage2, stage1)) {
    stage2 = query(n, remove);
    has_change(stage2, stage1);
  }

  // cout << "target_type: " << target_type << endl;
  int ans = 0;
  for (int i = 0; i < n; ++i) {
    if (stage2[i] == target_type) {
      ans = i+1;
      break;
    }
  }

  answer(ans);
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
