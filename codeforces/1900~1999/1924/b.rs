use std::io::{stdin, stdout, BufWriter, Write};
use std::str::FromStr;
use std::fmt::Debug;
use std::collections::BTreeMap;
use std::ops::Bound::*;
use std::cmp::{max, min};

fn read_vec<T: FromStr>() -> Vec<T> where <T as FromStr>::Err: Debug {
    let mut s = String::new();
    stdin().read_line(&mut s).unwrap();
    s.split(" ").map(|x| x.trim().parse().expect("invalid input")).collect()
}

struct SegmentTree {
    data: Vec<(i64,i64,i64)>,
    lazy: Vec<(i64,i64)>
}

impl SegmentTree {
    fn new(n: usize) -> Self {
        Self {
            data: vec![(0, 0, 0); (n+1) * 4],
            lazy: vec![(0, 0); (n+1) * 4],
        }
    }

    fn build(&mut self, i: usize, l: i32, r: i32, vals: &Vec<i64>, dist: &Vec<i64>) {
        if l == r {
            let idx = l as usize;
            self.data[i] = (vals[idx], dist[idx], vals[idx] * dist[idx]);
            return;
        }
        if l > r {
            return;
        }

        let m = l + (r - l) / 2;
        self.build(i * 2 + 1, l, m, vals, dist);
        self.build(i * 2 + 2, m + 1, r, vals, dist);
        
        let mut v = 0;
        if self.data[i*2+1].0 == self.data[i*2+2].0 {
            v = self.data[i*2+1].0;
        }
        let d = self.data[i*2+1].1 + self.data[i*2+2].1;
        let total = self.data[i*2+1].2 + self.data[i*2+2].2;
        self.data[i] = (v, d, total);
    }

    fn update(&mut self, i: usize, tl: i32, tr: i32, l: i32, r: i32, value: i64, dist: i64) {
        if tl > r || tr < l {
            return;
        }

        self.push(i, tl, tr);
        if tl >= l && tr <= r {
            let len = (tr - tl + 1) as i64;
            let v = self.data[i].0 + value;
            let d = self.data[i].1 + len * dist;
            let total = v * d;
            self.data[i] = (v, d, total);

            if tl != tr {
                self.lazy[i*2+1] = (self.lazy[i*2+1].0 + value, self.lazy[i*2+1].1 + dist);
                self.lazy[i*2+2] = (self.lazy[i*2+2].0 + value, self.lazy[i*2+2].1 + dist);
            }
            return;
        }

        let tm = tl + (tr - tl) / 2;
        if l <= tm {
            self.update(i * 2 + 1, tl, tm, l, r, value, dist);
        }
        if r > tm {
            self.update(i * 2 + 2, tm+1, tr, l, r, value, dist);
        }
        let v = value;
        let d = self.data[i*2+1].1 + self.data[i*2+2].1;
        let total = self.data[i*2+1].2 + self.data[i*2+2].2;
        self.data[i] = (v, d, total);
    }
    
    fn query(&mut self, i: usize, tl: i32, tr: i32, ql: i32, qr: i32) -> i64 {
        if tl > qr || tr < ql {
            return 0;
        }

        self.push(i, tl, tr);
        if tl >= ql && tr <= qr {
            return self.data[i].2;
        }

        let tm = tl + (tr - tl) / 2;
        return self.query(i * 2 + 1, tl, tm, ql, min(qr, tm)) +
            self.query(i * 2 + 2, tm+1, tr, max(ql, tm+1), qr);
    }

    fn push(&mut self, i: usize, tl: i32, tr: i32) {
        if self.lazy[i].0 != 0 || self.lazy[i].1 != 0 {
            let len = (tr - tl + 1) as i64;
            let value = self.data[i].0 + self.lazy[i].0;
            let dist = self.data[i].1 + self.lazy[i].1 * len;
            let total = value * dist;
            self.data[i] = (value, dist, total);

            if tl != tr {
                self.lazy[i*2+1] = (self.lazy[i*2+1].0 + self.lazy[i].0, self.lazy[i*2+1].1 + self.lazy[i].1);
                self.lazy[i*2+2] = (self.lazy[i*2+2].0 + self.lazy[i].0, self.lazy[i*2+2].1 + self.lazy[i].1);
            }
            self.lazy[i] = (0, 0);
        }
    }
}

fn solve() {
    let stdout = stdout();
    let mut writer = BufWriter::new(stdout.lock());

    let inputs = read_vec::<usize>();
    let n = inputs[0] as i32;
    let m = inputs[1];
    let q = inputs[2];

    let x = read_vec::<i32>();
    let v = read_vec::<i64>();

    let mut values: BTreeMap<i32, i64> = BTreeMap::new();
    for i in 0..m {
        values.entry(x[i]).or_insert(v[i]);
    }

    let mut vals = vec![0; (n+1) as usize];
    let mut dist = vec![0; (n+1) as usize];
    for pos in 1..=n {
        if let Some((rx, _)) = values.range((Included(&pos), Unbounded)).next() {
            dist[pos as usize] = (*rx - pos) as i64;
        }
        if let Some((_, lv)) = values.range((Unbounded, Excluded(&pos))).next_back() {
            vals[pos as usize] = *lv;
        }
    }

    let mut tree = SegmentTree::new(n as usize);
    tree.build(0, 0, n, &vals, &dist);

    for _i in 0..q {
        let query = read_vec::<i32>();
        let t = query[0];
        if t == 1 {
            let xi = query[1];
            let vi = query[2] as i64;

            let right = values.range((Included(&xi), Unbounded)).next().unwrap();
            let left = values.range((Unbounded, Excluded(&xi))).next_back().unwrap();
            tree.update(0, 0, n, xi+1, *right.0, vi - *left.1, 0);
            tree.update(0, 0, n, *left.0+1, xi, 0, -(*right.0 - xi) as i64);

            values.entry(xi).or_insert(vi);
        } else if t == 2 {
            let l = query[1];
            let r = query[2];

            let ans = tree.query(0, 0, n, l, r);
            writeln!(writer, "{}", ans).ok();
        }
    }
}

fn main() {
    solve();
}
