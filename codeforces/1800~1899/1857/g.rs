use std::io;
use std::str::FromStr;
use std::fmt::Debug;

const MOD: i64 = 998244353;

struct DisjointSet {
    parent: Vec<i32>,
    rank: Vec<i32>,
    size: Vec<i32>,
}

impl DisjointSet {
    pub fn new(n: usize) -> Self {
        DisjointSet {
            parent: (0..(n as i32)).collect(),
            rank: vec![0; n],
            size: vec![1; n],
        }
    }
    
    pub fn find(&mut self, x: usize) -> i32 {
        if (x as i32) != self.parent[x] {
            self.parent[x] = self.find(self.parent[x] as usize);
        }
        self.parent[x]
    }

    pub fn join(&mut self, x: usize, y: usize) {
        let px = self.find(x) as usize;
        let py = self.find(y) as usize;

        if px == py {
            return;
        }

        if self.rank[px] > self.rank[py] {
            self.parent[py] = px as i32;
            self.size[px] += self.size[py];
        } else if self.rank[py] > self.rank[px] {
            self.parent[px] = py as i32;
            self.size[py] += self.size[px];
        } else {
            self.parent[py] = px as i32;
            self.size[px] += self.size[py];
            self.rank[px] += 1;
        }
    }

    pub fn size(&mut self, x: usize) -> i32 {
        let p = self.find(x) as usize;
        self.size[p]
    } 
}

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

fn power(mut x: i64, mut n: i64) -> i64 {
    let mut ans: i64 = 1;
    while n > 0 {
        if n % 2 == 1 {
            ans *= x;
            ans %= MOD;
        }

        x = x * x;
        x %= MOD;
        n >>= 1;
    }

    ans
}

fn solve() {
    let inputs = read_vec::<i32>();
    let n = inputs[0] as usize;
    let s = inputs[1] as i64;

    let mut edges: Vec<(i32, i32, i64)> = Vec::new();
    for _i in 1..n {
        let row = read_vec::<i32>();
        edges.push((row[0], row[1], row[2] as i64));
    }

    edges.sort_by_key(|e| e.2);

    let mut ds = DisjointSet::new(n + 1);
    let mut ans: i64 = 1;
    for i in 0..edges.len() {
        let u = edges[i].0 as usize;
        let v = edges[i].1 as usize;
        let w = edges[i].2;

        let s1 = ds.size(u) as i64;
        let s2 = ds.size(v) as i64;

        ans *= power(s - w + 1, s1 * s2 - 1);
        ans %= MOD;

        ds.join(u, v);
    }

    println!("{}", ans);
}

fn main() {
    let n = read_int::<i32>();
    for _t in 0..n {
        solve();
    }
}
