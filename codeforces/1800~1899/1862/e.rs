use std::io::{stdin, stdout, BufWriter, Write};
use std::str::FromStr;
use std::fmt::Debug;
use std::collections::BinaryHeap;
use std::cmp::{Reverse, max};

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

    let inputs = read_vec::<i64>();
    let n = inputs[0] as usize;
    let m = inputs[1] as usize;
    let d = inputs[2];

    let a = read_vec::<i64>();
    let mut pq = BinaryHeap::new();
    let mut sum: i64 = 0;
    let mut ans: i64 = 0;
    for i in 0..n {
        if a[i] > 0 {
            sum += a[i];
            pq.push(Reverse(a[i]));
        }

        while pq.len() > m {
            sum -= pq.pop().unwrap().0;
        }
        
        let entertain = sum - ((i+1) as i64) * d;
        ans = max(ans, entertain);
    }

    writeln!(writer, "{}", ans).ok();
}

fn main() {
    let n = read_int::<i32>();
    for _t in 0..n {
        solve();
    }
}
