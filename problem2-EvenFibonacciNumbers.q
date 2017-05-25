B: 4000000;
N: 100;
f: {[x] t: sum[#[-2;x]]; $[t < B; (x, t); x]};
a: (f/)[N;(1;1)]
sum[a[where[mod[a;2] = 0]]]
//Answer: 4613732
