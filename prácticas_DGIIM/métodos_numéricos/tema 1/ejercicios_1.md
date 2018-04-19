# Cálculo del radio espectral  
	```maxima
m: matrix(
 [0,1], 
 [-1,0] 
);
apply( max , abs( eigenvalues(m)[1]));
```

# Norma inducida infinito y norma 1 inducida  

```maxima
/** Norma infinito inducidad**/
nii(x):=
(
    
    apply( max , makelist( apply("+" , abs(x[k])) , k, 1, matrix_size(x)[1]))
);

/** Norma 1 inducidad **/

n1i(x):=nii(transpose(x));

/** pruebas: **/
a:genmatrix( lambda([i,j],(j*2+i*3)*(-1)**(j+i+1)) , 3 ,3 );
"Norma infinito: ";
nii(a);
"Norma 1";
n1i(a);
```

# Condicicionamiento de una matrix a partir de la norma 1
```maxima
/** Condicionamiento de una matriz **/
cond1(n):=
(
    if determinant(n) = 0 then 
    (
        n, 
        "No es regular, cómase los mocos" 
    )
    else n1i(n)*n1i( invert(n))
);
```
