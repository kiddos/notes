use std::io::{stdin, stdout, BufWriter, Write};
use std::str::FromStr;
use std::fmt::Debug;
use std::collections::BinaryHeap;

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
    let mut c = read_vec::<i32>();
    let total: i64 = c.iter().map(|x| { *x as i64 }).sum::<i64>();
    let mut ones = total / n as i64;

    let mut ans = vec![0; n];
    if ones > 0 {
        let mut pq = BinaryHeap::new();
        for i in (0..n).rev() {
            while !pq.is_empty() && *pq.peek().unwrap() > i as i64 {
                pq.pop();
            }

            c[i] -= pq.len() as i32;

            let j = i as i64 - ones + 1;
            if c[i] == (i+1) as i32 {
                ans[i] = 1;
                ones -= 1;
            }
            if ones > 0 {
                pq.push(j);
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
