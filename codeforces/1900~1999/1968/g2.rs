use std::io::{stdin, stdout, BufWriter, Write};
use std::str::FromStr;
use std::fmt::Debug;
use std::cmp::min;
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

fn z_function(s: &Vec<char>) -> Vec<usize> {
    let n = s.len();
    let mut l = 0;
    let mut r = 0;
    let mut z = vec![0; n];
    for i in 1..n {
        if i < r {
            z[i] = min(r - i, z[i - l]);
        }
        while i + z[i] < n && s[z[i]] == s[i + z[i]] {
            z[i] += 1;
        }
        if i + z[i] > r {
            l = i;
            r = i + z[i];
        }
    }
    z
}

fn possible(z: &Vec<usize>, len: usize, k: usize) -> bool {
    let n = z.len();
    let mut i = len;
    let mut count = 1;
    while i < n {
        if z[i] >= len {
            i += len;
            count += 1;
        } else {
            i += 1;
        }
    }
    count >= k
}

fn solve() {
    let stdout = stdout();
    let mut writer = BufWriter::new(stdout.lock());
    let inputs = read_vec::<usize>();
    let n = inputs[0];
    let left = inputs[1];
    let right = inputs[2];
    let s: Vec<char> = read_str().chars().collect();

    let mut ans = vec![0; n+1];
    let z = z_function(&s);
    let sq = (n as f32).sqrt() as usize;
    for k in 1..=sq {
        let mut l = 1;
        let mut r = n / k;
        let mut result = 0;
        while l <= r {
            let mid = l + (r-l) / 2;
            if possible(&z, mid as usize, k) {
                l = mid + 1;
                result = mid;
            } else {
                r = mid - 1;
            }
        }
        ans[k] = result;
    }

    for len in 1..=sq {
        let mut k = 1;
        let mut i = len;
        while i < n {
            if z[i] >= len {
                k += 1;
                i += len
            } else {
                i += 1;
            }
        }
        ans[k] = max(ans[k], len);
    }

    for i in (1..n).rev() {
        ans[i] = max(ans[i], ans[i+1]);
    }

    for i in left..=right {
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
