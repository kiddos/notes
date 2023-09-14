use std::io::{stdin, stdout, BufWriter, Write};
use std::str::FromStr;
use std::fmt::Debug;

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

    let found_zero = a.iter().find(|&&x| x == 0).is_some();
    let max_val = *a.iter().max().unwrap() as usize;
    let mut counts: Vec<i32> = vec![0; max_val+1];
    let mut found_same = false;
    for i in 0..n {
        counts[a[i] as usize] += 1;
        if counts[a[i] as usize] >= 2 {
            found_same = true;
        }
    }

    let mut ans = 0;
    if !found_zero && !found_same {
        ans += 1;
    }

    for i in 0..n {
        if a[i] != 0 {
            ans += 1;
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
