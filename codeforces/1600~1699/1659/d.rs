use std::io::{stdin, stdout, BufWriter, Write};
use std::str::FromStr;
use std::fmt::Debug;
use std::cmp::*;

fn read_int<T: FromStr>() -> T where <T as FromStr>::Err: Debug {
    let mut s = String::new();
    stdin().read_line(&mut s).unwrap();
    s.trim().parse::<T>().expect("invalid input")
}

fn read_vec<T: FromStr>() -> Vec<T> where <T as FromStr>::Err: Debug {
    let mut s = String::new();
    stdin().read_line(&mut s).unwrap();
    s.split(" ").map(|x| x.trim().parse().expect("invalid input")).collect()
}

struct SegmentTree {
    data: Vec<i32>,
    lazy: Vec<i32>,
}

impl SegmentTree {
    fn new(a: &Vec<i32>) -> Self {
        let n = a.len();
        let mut data = vec![0; n * 4];

        SegmentTree::build(&mut data, 0, 0, n-1, a);

        SegmentTree {
            data: data,
            lazy: vec![0; n * 4],
        }
    }

    fn build(data: &mut Vec<i32>, i: usize, l: usize, r: usize, a: &Vec<i32>) {
        if l == r {
            data[i] = a[l];
            return;
        }

        if l > r {
            return;
        }

        let m = l + (r - l) / 2;
        SegmentTree::build(data, i * 2 + 1, l, m, a);
        SegmentTree::build(data, i * 2 + 2, m+1, r, a);
        data[i] = data[i*2+1] + data[i*2+2];
    }

    fn update(&mut self, i: usize, tl: usize, tr: usize, l: usize, r: usize, x: i32) {
        if tl > r || tr < l {
            return;
        }

        self.push(i, tl, tr);
        if tl >= l && tr <= r {
            self.data[i] += (tr - tl + 1) as i32 * x;
            if tl != tr {
                self.lazy[i * 2 + 1] += x;
                self.lazy[i * 2 + 2] += x;
            }
            return;
        }

        let tm = tl + (tr - tl) / 2;
        if l <= tm {
            self.update(i * 2 + 1, tl, tm, l, r, x);
        }
        if r > tm {
            self.update(i * 2 + 2, tm+1, tr, l, r, x);
        }
        self.data[i] = self.data[i * 2 + 1] + self.data[i * 2 + 2];
    }

    fn query(&mut self, i: usize, tl: usize, tr: usize, ql: usize, qr: usize) -> i32 {
        if tr < ql || tl > qr {
            return 0;
        }

        self.push(i, tl, tr);
        if tl >= ql && tr <= qr {
            return self.data[i];
        }
        
        let tm = tl + (tr - tl) / 2;
        self.query(i * 2 + 1, tl, tm, ql, min(qr, tm)) +
            self.query(i * 2 + 2, tm+1, tr, max(ql, tm+1), qr)
    }

    fn push(&mut self, i: usize, tl: usize, tr: usize) {
        if self.lazy[i] != 0 {
            self.data[i] += (tr - tl + 1) as i32 * self.lazy[i];
            if tl != tr {
                self.lazy[i * 2 + 1] += self.lazy[i];
                self.lazy[i * 2 + 2] += self.lazy[i];
            }
            self.lazy[i] = 0;
        }
    }
}

fn solve() {
    let stdout = stdout();
    let mut writer = BufWriter::new(stdout.lock());
    let n = read_int::<usize>();
    let c = read_vec::<i32>();
    let total: i64 = c.iter().map(|x| { *x as i64 }).sum::<i64>();
    let mut ones = total / n as i64;

    let mut ans = vec![0; n];
    if ones > 0 {
        let mut tree = SegmentTree::new(&c);
        for i in (0..n).rev() {
            let i1 = i as i64 - ones + 1;
            let i2 = i;
            if tree.query(0, 0, n-1, i, i) == (i+1) as i32 {
                ans[i] = 1;
                ones -= 1;
            }
            if ones > 0 {
                tree.update(0, 0, n-1, i1 as usize, i2, -1);
            }
        }
    }

    for i in 0..n {
        write!(writer, "{} ", ans[i]).ok();
    }
    writeln!(writer).ok();
}

fn main() {
    let n = read_int::<i32>();
    for _t in 0..n {
        solve();
    }
}
