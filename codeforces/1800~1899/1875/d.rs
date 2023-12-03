use std::io::{stdin, stdout, BufWriter, Write};
use std::str::FromStr;
use std::fmt::Debug;
use std::cmp::min;
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
    let a = read_vec::<i64>();
    let mut freq = BTreeMap::new();

    for i in 0..n {
        freq.entry(&a[i]).and_modify(|c| *c += 1).or_insert(1);
    }

    let mut mex = 0;
    while freq.contains_key(&mex) {
        mex += 1;
    }

    let inf = i32::MAX;
    let mut dp = vec![inf as i64; (mex+1) as usize];
    dp[mex as usize] = 0;
    for i in (0..=mex).rev() {
        for j in 0..i {
            let j_count = *freq.get(&j).unwrap();
            dp[j as usize] = min(dp[j as usize], dp[i as usize] + i * (j_count - 1) + j);
        }
    }

    writeln!(writer, "{}", dp[0]).ok();
}

fn main() {
    let n = read_int::<i32>();
    for _t in 0..n {
        solve();
    }
}
