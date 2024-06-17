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

fn manacher(s: &Vec<char>) -> Vec<i32> {
    let mut t = Vec::new();
    t.push('^');
    t.push('#');
    for &ch in s.iter() {
        t.push(ch);
        t.push('#');
    }
    t.push('$');

    let n = t.len();
    let mut p = vec![0; n];
    let mut l: i32 = 1;
    let mut r: i32 = 1;
    for i in 1..(n-1) {
        p[i] = (r - i as i32).min(p[(l + r) as usize - i]);
        p[i] = p[i].max(0);
        while t[i + p[i] as usize] == t[i -  p[i] as usize] {
            p[i] += 1;
        }
        if i as i32 + p[i] > r {
            l = i as i32 - p[i];
            r = i as i32 + p[i];
        }
    }
    p.into_iter().skip(1).take(n-1).collect()
}

fn is_palindrome(l: usize, r: usize, p: &Vec<i32>) -> bool {
    let len = r - l + 1;
    let palindrome_len = p[l * 2 + len] as usize - 1;
    palindrome_len >= len
}

fn compute_next_diff(s: &Vec<char>) -> Vec<usize> {
    let n = s.len();
    let mut next_diff = vec![n; n];
    let mut st = Vec::new();
    for i in (0..n).step_by(2) {
        while !st.is_empty() && s[st[st.len()-1]] != s[i] {
            next_diff[st[st.len()-1]] = i;
            st.pop();
        }
        st.push(i);
    }
    st.clear();
    for i in (1..n).step_by(2) {
        while !st.is_empty() && s[st[st.len()-1]] != s[i] {
            next_diff[st[st.len()-1]] = i;
            st.pop();
        }
        st.push(i);
    }
    next_diff
}

fn is_alternating(l: usize, r: usize, next_diff: &Vec<usize>) -> bool {
    let i1 = next_diff[l];
    let i2 = next_diff[l+1];
    i1 > r && i2 > r
}

fn compute_char_counts(s: &Vec<char>) -> Vec<Vec<i32>> {
    let n = s.len();
    let mut chars = vec![vec![0; n+1]; 26];
    for i in 1..=n {
        let c = (s[i-1] as u8 - b'a') as usize;
        chars[c][i] += 1;
    }
    for c in 0..26 {
        for i in 1..=n {
            chars[c][i] += chars[c][i-1];
        }
    }
    chars
}

fn is_all_same(l: usize, r: usize, chars: &Vec<Vec<i32>>) -> bool {
    let len = (r - l + 1) as i32;
    for c in 0..26 {
        let count = chars[c][r+1] - chars[c][l];
        if count != 0 && count != len {
            return false;
        }
    }
    true
}

fn solve() {
    let stdout = stdout();
    let mut writer = BufWriter::new(stdout.lock());
    let inputs = read_vec::<usize>();
    let q = inputs[1];
    let s: Vec<char> = read_str().chars().collect();

    let p = manacher(&s);
    let next_diff = compute_next_diff(&s);
    let chars = compute_char_counts(&s);

    for _i in 0..q {
        let query = read_vec::<usize>();
        let l = query[0] - 1;
        let r = query[1] - 1;
        let mut ans: i64 = 0;

        let mut len = (r - l) as i64;
        if len >= 3 && !is_alternating(l, r, &next_diff) {
            let l = if len % 2 == 1 { len } else { len - 1 };
            ans += (l + 3) * ((l - 3) / 2 + 1) / 2;
        }

        if len >= 2 && !is_all_same(l, r, &chars) {
            let l = if len % 2 == 0 { len } else { len - 1 };
            ans += (l + 2) * ((l - 2) / 2 + 1) / 2;
        }

        len = (r - l + 1) as i64;
        if !is_palindrome(l, r, &p) {
            ans += len;
        }
        writeln!(writer, "{}", ans).ok();
    }
}

fn main() {
    let n = read_int::<i32>();
    for _t in 0..n {
        solve();
    }
}
