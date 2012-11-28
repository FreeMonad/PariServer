Note
=====

This project is superceded by GPP and will no longer be updated.

Sample Client Session
======================
```
Trying to connect...
Connected.
(gp)> 2+2
? 4
(gp)> primes(2)
? [2, 3]
(gp)> primes(20)
? [2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 53, 59, 61, 67, 71]
(gp)> %
? [2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 53, 59, 61, 67, 71]
(gp)> fibonacci(100)
? 354224848179261915075
(gp)> %*2
? 708449696358523830150
(gp)> help(polgalois)
? polgalois(T): Galois group of the polynomial T (see manual for group coding). Return [n, s, k, name] where n is the group order, s the signature, k the index and name is the GAP4 name of the transitive group.

(gp)> polgalois(x^3-2)
? [6, -1, 1, "S3"]
(gp)> ^C
```

Sample Server Session
=====================
```
Waiting for a connection...
Connected.
Waiting for a connection...
^C
```