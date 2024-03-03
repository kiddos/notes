use std::io::{stdin, stdout, BufWriter, Write};
use std::str::FromStr;
use std::fmt::Debug;

struct FenwickTree {
    data: Vec<i32>,
}

impl FenwickTree {
    fn new(n: usize) -> Self {
        FenwickTree {
            data: vec![0; n+1],
        }
    }

    fn get(&self, mut i: i32) -> i32 {
        let mut total = 0;
        while i > 0 {
            total += self.data[i as usize];
            i -= i & (-i);
        }
        total
    }

    fn update(&mut self, mut i: i32, x: i32) {
        let n = self.data.len() as i32;
        while i < n {
            self.data[i as usize] += x;
            i += i & (-i);
        }
    }
}

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

fn solve() {
    let stdout = stdout();
    let mut writer = BufWriter::new(stdout.lock());
    let n = read_int::<usize>();
    let mut a = read_vec::<i32>();
    a.insert(0, 0);

    let mut tree = FenwickTree::new(n*2+1);
    let mut b = vec![0; 2*n+1];
    for i in 1..=n {
        b[i] = a[i];
    }
    for i in n+1..=2*n {
        b[i] = a[i-n] + n as i32;
    }

    let mut ans = vec![0; n+1];
    for i in (1..=2*n).rev() {
        let mut r = b[i];
        if r < i as i32 {
            r += n as i32;
        }
        if i <= n {
            ans[b[i] as usize] = r - (i as i32) - (tree.get(r) - tree.get(i as i32));
        }
        tree.update(r, 1);
    }

    for i in 1..=n {
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
