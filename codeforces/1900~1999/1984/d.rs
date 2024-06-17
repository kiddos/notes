use std::io::{stdin, stdout, BufWriter, Write};
use std::str::FromStr;
use std::fmt::Debug;
use std::cmp::{min, max};

fn read_int<T: FromStr>() -> T where <T as FromStr>::Err: Debug {
    let mut s = String::new();
    stdin().read_line(&mut s).unwrap();
    s.trim().parse::<T>().expect("invalid input")
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
            z[i] = min(r-i, z[i-l]);
        }
        while i + z[i] < n && s[z[i]] == s[z[i] + i] {
            z[i] += 1;
        }
        if i + z[i] > r {
            l = i;
            r = i + z[i];
        }
    }
    z
}

fn solve() {
    let stdout = stdout();
    let mut writer = BufWriter::new(stdout.lock());
    let s: Vec<char> = read_str().chars().collect();
    let n = s.len();

    let mut indices = Vec::new();
    for i in 0..n {
        if s[i] != 'a' {
            indices.push(i);
        }
    }
    
    if indices.len() == 0 {
        writeln!(writer, "{}", n - 1).ok();
        return;
    }

    let s2: Vec<char> = s.iter().skip(indices[0]).map(|&i| i).collect();
    let z = z_function(&s2);
    let m = indices.len();
    let mut ans: i64 = 0;
    for len in 1..=m {
        if m % len == 0 {
            let size = indices[len-1] - indices[0] + 1;
            let mut valid = true;
            for i in (len..m).step_by(len) {
                if z[indices[i] - indices[0]] < size {
                    valid = false;
                    break;
                }
            }

            if valid {
                let mut p = indices[0];
                for i in (len..m).step_by(len) {
                    p = p.min(indices[i] - indices[i-1] - 1);
                }
                let mut s = n+1;
                if len + 1 <= m {
                    for i in (0..=(m-len-1)).rev().step_by(len) {
                        s = s.min(indices[i+1] - indices[i] - 1);
                    }
                }

                for i in 0..=p {
                    let suffix = min(max(s as i64 - i as i64, 0), n as i64 - indices[m-1] as i64 - 1);
                    ans += suffix + 1;
                }
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
