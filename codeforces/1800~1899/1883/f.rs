use std::io::{stdin, stdout, BufWriter, Write};
use std::str::FromStr;
use std::fmt::Debug;
use std::collections::BTreeMap;

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
    let a = read_vec::<i32>();

    let mut count = BTreeMap::new();
    let mut left = vec![0; n];
    for i in 0..n {
        if !count.contains_key(&a[i]) {
            left[i] = 1;
        }
        count.entry(a[i]).and_modify(|c| *c += 1).or_insert(1);
    }

    let mut l: i64 = 0;
    let mut ans: i64 = 0;
    for i in 0..n {
        l += left[i];
        count.entry(a[i]).and_modify(|c| *c -= 1);
        if let Some(c) = count.get(&a[i]) {
            if *c == 0 {
                ans += l;
            }
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
