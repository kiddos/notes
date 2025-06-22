struct DisjointSet {
    parent: Vec<usize>,
    rank: Vec<i32>,
}

impl DisjointSet {
    fn new(n: usize) -> Self {
        DisjointSet {
            parent: (0..n).collect(),
            rank: vec![0; n],
        }
    }

    fn find(&mut self, x: usize) -> usize {
        if x != self.parent[x] {
            self.parent[x] = self.find(self.parent[x]);
        }
        self.parent[x]
    }

    fn join(&mut self, x: usize, y: usize) {
        let px = self.find(x);
        let py = self.find(y);
        if px == py {
            return;
        }
        if self.rank[px] > self.rank[py] {
            self.parent[py] = px;
        } else if self.rank[py] > self.rank[px] {
            self.parent[px] = py;
        } else {
            self.parent[py] = px;
            self.rank[px] += 1;
        }
    }
}

fn main() {
    let mut ds = DisjointSet::new(10);
    ds.join(0, 1);
    ds.join(1, 3);
    ds.join(2, 5);
    ds.join(2, 6);

    use std::collections::HashMap;
    let mut groups: HashMap<usize, Vec<usize>> = HashMap::new();
    for i in 0..10 {
        let root = ds.find(i);
        groups.entry(root).or_insert(Vec::new()).push(i);
    }

    for (group_id, members) in groups {
        print!("group {} has : ", group_id);
        for &member in &members {
            print!("{} ", member);
        }
        println!();
    }
}
