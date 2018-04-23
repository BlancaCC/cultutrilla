# Resolución hacia arriba
``` maxima
n:3;
m: genmatrix( lambda( [i,j],j+3*i), 3,3);
b:[1,1,1];
s:[0,0,0];

for i: n step -1 thru 1 do
(
    s[i]:sum( m[i,k] *b[k], k , i, n)
    
);
s;

```

# Doolitle
```
n:matrix_size(a)[1];
for j:1 thru n do
(
    for i:j thru n do
    (
        s[i,j]: a[i,j] - sum( s[j,k]*s[k,i],k , i,n )
    ),
    for i:j+1 thru n do 
    (
        s[j,i]: (a[j,i] - sum ( s[i,k]*s[k,j], k, i , n)) / s[i,i]
    )
);
float(s);
```
