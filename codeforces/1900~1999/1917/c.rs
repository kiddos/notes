use std::io::{stdin, stdout, BufWriter, Write};
use std::str::FromStr;
use std::fmt::Debug;
use std::cmp::{max, min};

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
    let k = inputs[1] as usize;
    let d = inputs[2];

    let mut a = read_vec::<i32>();
    let v = read_vec::<i32>();

    let max_val = min(d-1, 2 * n as i64);
    let mut ans = 0;
    for i in 0..=max_val {
        let mut current = (d - (i as i64) - 1) / 2;
        for j in 0..n {
            if a[j] == (j+1) as i32 {
                current += 1;
            }
        }
        ans = max(ans, current);

        for j in 0..v[i as usize % k] {
            a[j as usize] += 1;
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
