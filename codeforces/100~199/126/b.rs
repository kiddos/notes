use std::io::{stdin, stdout, BufWriter, Write};
use std::cmp::min;
use std::collections::VecDeque;

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

    let s0 = read_str();
    let s = s0.chars().collect::<Vec<char>>();
    let n = s.len();
    let z = z_function(&s);

    let mut ans = 0;
    let mut d = VecDeque::new();
    for i in 1..n {
        if z[i] == 0 {
            continue;
        }

        if z[i] + i == n {
            if let Some(&len) = d.front() {
                if len >= z[i] {
                    ans = ans.max(z[i]);
                }
            }
        }
        while !d.is_empty() && *d.back().unwrap() < z[i] {
            d.pop_back();
        }
        d.push_back(z[i]);
    }

    if ans == 0 {
        writeln!(writer, "Just a legend").ok();
    } else {
        let slice: String = s0.chars().take(ans).collect();
        writeln!(writer, "{}", slice).ok();
    }
}

fn main() {
    solve();
}
