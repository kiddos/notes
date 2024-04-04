use std::io::{stdin, stdout, BufWriter, Write};
use std::str::FromStr;
use std::fmt::Debug;
use std::collections::{BTreeMap, BTreeSet};
use std::ops::Bound::*;
use std::cmp::{max, min};

fn read_int<T: FromStr>() -> T where <T as FromStr>::Err: Debug {
    let mut s = String::new();
    stdin().read_line(&mut s).unwrap();
    s.trim().parse::<T>().expect("invalid input")
}

fn read_vec<T: FromStr>() -> Vec<T> where <T as FromStr>::Err: Debug {
    let mut s = String::new();
    stdin().read_line(&mut s).unwrap();
    if s.trim().is_empty() {
        return Vec::new();
    }
    s.split(" ").map(|x| x.trim().parse().expect("invalid input")).collect()
}

struct SegmentTree {
    data: Vec<i32>,
    lazy: Vec<i32>,
}

impl SegmentTree {
    fn new(n: usize) -> Self {
        Self {
            data: vec![0; n * 4],
            lazy: vec![0; n * 4],
        }
    }

    fn push(&mut self, i: usize, tl: i32, tr: i32) {
        if self.lazy[i] != 0 {
            if tl != tr {
                self.data[i * 2 + 1] += self.lazy[i];
                self.lazy[i * 2 + 1] += self.lazy[i];

                self.data[i * 2 + 2] += self.lazy[i];
                self.lazy[i * 2 + 2] += self.lazy[i];
            }
            self.lazy[i] = 0;
        }
    }

    fn update(&mut self, i: usize, tl: i32, tr: i32, l: i32, r: i32, x: i32) {
        if tr < l || tl > r {
            return;
        }

        if tl >= l && tr <= r {
            self.data[i] += x;
            self.lazy[i] += x;
            return;
        }

        self.push(i, tl, tr);
        let tm = tl + (tr - tl) / 2;
        if l <= tm {
            self.update(i * 2 + 1, tl, tm, l, r, x);
        }
        if r > tm {
            self.update(i * 2 + 2, tm + 1, tr, l, r, x);
        }
        self.data[i] = max(self.data[i * 2 + 1], self.data[i * 2 + 2]);
    }

    fn query_max(&mut self, i: usize, tl: i32, tr: i32, ql: i32, qr: i32) -> i32 {
        if tr < ql || tl > qr {
            return 0;
        }

        if tl >= ql && tr <= qr {
            return self.data[i];
        }

        self.push(i, tl, tr);

        let tm = tl + (tr - tl) / 2;
        let left = self.query_max(i * 2 + 1, tl, tm, ql, min(qr, tm));
        let right = self.query_max(i * 2 + 2, tm + 1, tr, max(ql, tm+1), qr);
        max(left, right)
    }
}

fn dfs1(node: usize, adj: &Vec<Vec<usize>>, t: &mut i32, t_in: &mut Vec<i32>, t_out: &mut Vec<i32>) {
    *t += 1;
    t_in[node] = *t;
    for &next_node in adj[node].iter() {
        dfs1(next_node, adj, t, t_in, t_out);
    }
    t_out[node] = *t;
}
fn dfs2(node: usize, adj: &Vec<Vec<usize>>, a: &Vec<i32>, t: i32, t_in: &Vec<i32>, t_out: &Vec<i32>, group: &mut BTreeMap<i32, BTreeSet<(i32, usize)>>, tree: &mut SegmentTree, ans: &mut i64) {
    for &next_node in adj[node].iter() {
        dfs2(next_node, adj, a, t, t_in, t_out, group, tree, ans);
    }

    let s = group.entry(a[node]).or_insert(BTreeSet::new());
    let mut found = Vec::new();
    let n = adj.len();
    for &(t2, node2) in s.range((Included((t_in[node], 0)), Included((t_out[node], n)))) {
        tree.update(0, 0, t, t_in[node2], t_out[node2], -1);
        found.push((t2, node2));
    }
    for item in found.iter() {
        s.remove(item);
    }

    s.insert((t_in[node], node));
    tree.update(0, 0, t, t_in[node], t_out[node], 1);

    let mut last: i64 = 1;
    for &next_node in adj[node].iter() {
        let result = tree.query_max(0, 0, t, t_in[next_node], t_out[next_node]);
        *ans = max(*ans, result as i64 * last);
        last = max(last, result as i64);
    }
}

fn solve() {
    let stdout = stdout();
    let mut writer = BufWriter::new(stdout.lock());
    let n = read_int::<usize>();

    let mut adj = vec![Vec::new(); n+1];
    let p = read_vec::<usize>();
    for i in 0..p.len() {
        adj[p[i]].push(i+2);
    }

    let mut a = read_vec::<i32>();
    a.insert(0, 0);

    let mut t_in = vec![0; n+1];
    let mut t_out = vec![0; n+1];
    let mut t = 0;
    dfs1(1, &adj, &mut t, &mut t_in, &mut t_out);

    let mut tree = SegmentTree::new((t+1) as usize);

    let mut ans = 1;
    let mut group = BTreeMap::new();
    dfs2(1, &adj, &a, t, &t_in, &t_out, &mut group, &mut tree, &mut ans);

    writeln!(writer, "{}", ans).ok();
}

fn main() {
    let n = read_int::<i32>();
    for _t in 0..n {
        solve();
    }
}
