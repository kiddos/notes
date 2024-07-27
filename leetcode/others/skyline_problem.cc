#include <bits/stdc++.h>

using namespace std;

class Solution {
 public:
  int getMaxHeight(multiset<int>& heights) {
    if (heights.size() == 0) return 0;
    return (*heights.rbegin());
  }

  vector<vector<int>> getSkyline(vector<vector<int>>& buildings) {
    vector<pair<int, int>> events;
    int n = buildings.size();
    for (int i = 0; i < n; ++i) {
      events.push_back({buildings[i][0], buildings[i][2]});
      events.push_back({buildings[i][1], -buildings[i][2]});
    }

    sort(events.begin(), events.end(), [](auto p1, auto p2) {
      if (p1.first == p2.first) {
        return p1.second > p2.second;
      }
      return p1.first < p2.first;
    });

    vector<vector<int>> ans;
    multiset<int> heights;
    for (auto e : events) {
      if (e.second > 0) {
        if (e.second > getMaxHeight(heights)) {
          ans.push_back({e.first, e.second});
        }
        heights.insert(e.second);
      } else {
        // erase just 1
        heights.erase(heights.equal_range(-e.second).first);
        if (-e.second > getMaxHeight(heights)) {
          ans.push_back({e.first, getMaxHeight(heights)});
        }
      }
    }
    return ans;
  }
};

ostream& operator<<(ostream& os, const map<int, int>& m) {
  for (auto it = m.cbegin(); it != m.cend(); ++it) {
    os << "(" << it->first << ", " << it->second << "), ";
  }
  return os;
}

class Solution2 {
 public:
  vector<vector<int>> getSkyline(vector<vector<int>>& buildings) {
    set<int> end_points;
    for (auto b : buildings) {
      end_points.insert(b[0]);
      end_points.insert(b[1]);
    }

    vector<vector<int>> ans;
    int last_height = 0;
    priority_queue<pair<int, int>> active;
    auto it = buildings.begin();

    for (int x : end_points) {
      while (it != buildings.end() && it->at(0) < x) {
        active.push({it->at(2), it->at(1)});
        it++;
      }

      while (!active.empty() && active.top().second <= x) {
        active.pop();
      }

      int h = 0;
      if (!active.empty()) h = active.top().first;

      if (h != last_height) {
        ans.push_back({x, h});
        last_height = h;
      }
    }
    return ans;
  }
};

class Solution3 {
 public:
  struct Point {
    int x, h;
    bool start;
  };

  vector<vector<int>> getSkyline(vector<vector<int>>& buildings) {
    vector<Point> points;
    for (auto b : buildings) {
      points.push_back(Point{b[0], b[2], true});
      points.push_back(Point{b[1], b[2], false});
    }
    sort(points.begin(), points.end(), [](auto p1, auto p2) {
      if (p1.x == p2.x) {
        return (p1.start ? p1.h : -p1.h) > (p2.start ? p2.h : -p2.h);
      }
      return p1.x < p2.x;
    });

    map<int, int, greater<int>> queue;

    vector<vector<int>> ans;
    int maxval = 0;
    for (auto p : points) {
      if (p.start) {
        queue[p.h]++;
      } else {
        queue[p.h]--;
        if (queue[p.h] == 0) {
          queue.erase(p.h);
        }
      }

      int queue_max = queue.empty() ? 0 : queue.begin()->first;
      if (maxval != queue_max) {
        ans.push_back({p.x, queue_max});
        maxval = queue_max;
      }
    }
    return ans;
  }
};


class Solution4 {
 public:
  vector<vector<int>> getSkyline(vector<vector<int>>& buildings) {
    return merge(buildings, 0, buildings.size()-1);
  }

  vector<vector<int>> merge(vector<vector<int>>& buildings, int l, int r) {
    if (l < r) {
      int mid = l + (r-l) / 2;
      return merge(merge(buildings, l, mid), merge(buildings, mid+1, r));
    } else {
      return {{buildings[l][0], buildings[l][2]}, {buildings[l][1], 0}};
    }
  }

  vector<vector<int>> merge(const vector<vector<int>>& s1, const vector<vector<int>>& s2) {
    vector<vector<int>> ans;
    int h1 = 0, h2 = 0;
    int i = 0, j = 0;
    while (i < s1.size() && j < s2.size()) {
      int x = 0, h = 0;
      if (s1[i][0] < s2[j][0]) {
        x = s1[i][0];
        h1 = s1[i++][1];
        h = max(h2, h1);
      } else if (s2[j][0] < s1[i][0]) {
        x = s2[j][0];
        h2 = s2[j++][1];
        h = max(h1, h2);
      } else {
        x = s1.front()[0];
        h1 = s1[i++][1];
        h2 = s2[j++][1];
        h = max(h1, h2);
      }

      if (ans.size() == 0 || h != ans.back()[1]) {
        ans.push_back({x, h});
      }
    }
    while (i < s1.size()) ans.push_back(s1[i++]);
    while (j < s2.size()) ans.push_back(s2[j++]);
    return ans;
  }
};

class Solution5 {
 public:
  vector<vector<int>> getSkyline(vector<vector<int>>& buildings) {
    multiset<pair<int, int>> seq;
    for (auto b : buildings) {
      seq.emplace(make_pair(b[0], -b[2]));
      seq.emplace(make_pair(b[1], b[2]));
    }

    vector<vector<int>> ans;
    pair<int, int> curr;
    multiset<int> heights({0});
    for (auto p : seq) {
      if (p.second < 0) heights.emplace(-p.second);
      else heights.erase(heights.find(p.second));
      if (curr.second != *heights.rbegin()) {
        curr.first = p.first;
        curr.second = *heights.rbegin();
        ans.push_back({curr.first, curr.second});
      }
    }
    return ans;
  }
};

int main(void) {
  int T = 0;
  cin >> T;
  for (int t = 0; t < T; ++t) {
    int n = 0;
    cin >> n;
    vector<vector<int>> buildings(n);
    for (int i = 0; i < n; ++i) {
      int x1 = 0, x2 = 0, h = 0;
      cin >> x1 >> x2 >> h;
      buildings[i] = {x1, x2, h};
    }

    vector<vector<int>> ans = Solution().getSkyline(buildings);
    for (vector<int> a : ans) {
      cout << "(" << a[0] << "," << a[1] << ") ";
    }
    cout << endl;

    ans = Solution2().getSkyline(buildings);
    for (vector<int> a : ans) {
      cout << "(" << a[0] << "," << a[1] << ") ";
    }
    cout << endl;

    ans = Solution3().getSkyline(buildings);
    for (vector<int> a : ans) {
      cout << "(" << a[0] << "," << a[1] << ") ";
    }
    cout << endl;

    ans = Solution4().getSkyline(buildings);
    for (vector<int> a : ans) {
      cout << "(" << a[0] << "," << a[1] << ") ";
    }
    cout << endl;

    ans = Solution5().getSkyline(buildings);
    for (vector<int> a : ans) {
      cout << "(" << a[0] << "," << a[1] << ") ";
    }
    cout << endl;
  }
  return 0;
}
