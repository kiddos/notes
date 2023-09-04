use std::io;
use std::str::FromStr;
use std::fmt::Debug;

fn read_int<T: FromStr>() -> T where <T as FromStr>::Err: Debug {
    let mut s = String::new();
    io::stdin().read_line(&mut s).unwrap();
    s.trim().parse::<T>().expect("invalid input")
}

fn read_vec<T: FromStr>() -> Vec<T> where <T as FromStr>::Err: Debug {
    let mut s = String::new();
    io::stdin().read_line(&mut s).unwrap();
    s.split(" ").map(|x| x.trim().parse().expect("invalid input")).collect()
}

fn query(s: String) -> i64 {
    println!("? {}", s);
    read_int::<i64>()
}

fn answer(l: i64) {
    println!("! {}", l);
}

fn solve() {
    let inputs = read_vec::<usize>();
    let m = inputs[1];

    let mut s = vec![b'0'; m];
    let mut lengths = vec![0; m];
    for i in 0..m {
        s[i] = b'1';
        lengths[i] = query(String::from_utf8(s.clone()).unwrap());
        s[i] = b'0';
    }

    let mut tracks: Vec<(i64,usize)> = Vec::new();
    for i in 0..m {
        tracks.push((lengths[i], i));
    }
    tracks.sort();

    let mut ans = 0;
    for i in 0..m {
        let idx = tracks[i].1;
        s[idx] = b'1';
        let value = query(String::from_utf8(s.clone()).unwrap());
        if value == ans + tracks[i].0 {
            ans = value;
        } else {
            s[idx] = b'0';
        }
    }

    answer(ans);
}

fn main() {
    solve();
}
