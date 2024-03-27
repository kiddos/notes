#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

struct Student {
  int k, s, t;
};

struct CompareStudent {
  bool operator()(const Student& s1, const Student& s2) const {
    if (s1.k == s2.k) {
      if (s1.t == s2.t) {
        return s1.s > s2.s;
      }
      return s1.t > s2.t;
    }
    return s1.k < s2.k;
  }
};

void solve() {
  int n = 0, D = 0;
  cin >> n >> D;
  vector<Student> students;
  for (int i = 0; i < n; ++i) {
    int k = 0, s = 0;
    cin >> k >> s;
    students.push_back(Student{k, s, i});
  }

  vector<int> suffix_max(n);
  for (int i = n-1; i >= 0; --i) {
    suffix_max[i] = students[i].k;
    if (i+1 < n) suffix_max[i] = max(suffix_max[i], suffix_max[i+1]);
  }

  priority_queue<Student, vector<Student>, CompareStudent> pq;
  int idx = 0;
  vector<vector<Student>> to_add(D+1);
  for (int t = 1; t <= D; ++t) {
    if (pq.empty() || pq.top().k <= suffix_max[idx]) {
      // advance idx
      i64 t2 = (i64)t + students[idx].s;
      if (t2 <= D) {
        to_add[t2].push_back(students[idx]);
      }

      idx++;
      if (idx == n) {
        cout << t << endl;
        return;
      }
    } else {
      auto s = pq.top();
      pq.pop();
      i64 t2 = (i64)t + s.s;
      if (t2 <= D) {
        to_add[t2].push_back(s);
      }
    }

    for (auto s : to_add[t]) {
      pq.push(Student{s.k, s.s, t});
    }
  }

  cout << "-1" << endl;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);

  int T = 0;
  cin >> T;
  for (int t = 0; t < T; ++t) {
    solve();
  }
  return 0;
}