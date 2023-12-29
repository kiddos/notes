use std::io::{stdin, stdout, BufWriter, Write};
use std::str::FromStr;
use std::fmt::Debug;
use std::collections::BinaryHeap;
use std::cmp::Reverse;

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
    let p = inputs[1];
    let a = read_vec::<i64>();
    let b = read_vec::<i64>();

    let mut pq = BinaryHeap::new();
    pq.push(Reverse((p, n as i64)));
    let mut residents = Vec::new();
    for i in 0..n {
        residents.push((b[i], a[i]));
    }
    residents.sort();

    let mut ans: i64 = 0;
    for i in 0..n {
        if let Some(Reverse((bi, ai))) = pq.pop() {
            ans += bi;
            if ai-1 > 0 {
                pq.push(Reverse((bi, ai-1)));
            }
            pq.push(Reverse(residents[i]));
        }
    }

    writeln!(writer, "{}", ans).ok();
}

fn main() {
    let n = read_int::<i32>();
    for _t in 0..n {
        solve();
    }
}
