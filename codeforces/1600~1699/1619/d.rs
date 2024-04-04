use std::io::{stdin, stdout, BufWriter, Write};
use std::str::FromStr;
use std::fmt::Debug;
use std::cmp::max;

fn read_int<T: FromStr>() -> T where <T as FromStr>::Err: Debug {
    let mut s = String::new();
    stdin().read_line(&mut s).unwrap();
    s.trim().parse::<T>().expect("invalid input")
}

fn read_vec<T: FromStr>() -> Vec<T> where <T as FromStr>::Err: Debug {
    let mut s = String::new();
    stdin().read_line(&mut s).unwrap();
    if s.is_empty() {
        return Vec::new();
    }
    s.split(" ").map(|x| x.trim().parse().expect("invalid input")).collect()
}

fn read_str() -> String {
    let mut s = String::new();
    stdin().read_line(&mut s).unwrap();
    s.trim().to_string()
}

fn solve() {
    let stdout = stdout();
    let mut writer = BufWriter::new(stdout.lock());

    let _empty = read_str();
    let inputs = read_vec::<usize>();
    let m = inputs[0];
    let n = inputs[1];
    let mut p: Vec<Vec<i32>> = Vec::new();
    for _i in 0..m {
        let row = read_vec::<i32>();
        p.push(row);
    }

    let mut max_val = 0;
    for i in 0..m {
        for j in 0..n {
            max_val = max(max_val, p[i][j]);
        }
    }

    let possible = |x: i32| -> bool {
        // check if there is a gift with value >= x for each friend
        for j in 0..n {
            let mut found = false;
            for i in 0..m {
                if p[i][j] >= x {
                    found = true;
                    break;
                }
            }
            if !found {
                return false;
            }
        }

        // check if there is a store with 2 gifts >= x
        for i in 0..m {
            let mut count = 0;
            for j in 0..n {
                if p[i][j] >= x {
                    count += 1;
                }
            }
            if count >= 2 {
                return true;
            }
        }
        false
    };

    let mut l = 1;
    let mut r = max_val;
    let mut ans = 1;
    while l <= r {
        let mid = l + (r - l) / 2;
        if possible(mid) {
            ans = mid;
            l = mid + 1;
        } else {
            r = mid - 1;
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
