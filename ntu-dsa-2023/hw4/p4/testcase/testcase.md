# 1
Correctness check

## 1-01 ~ 1-10
No rotational strings (any two strings are either completely identical or not rotationaly identical)

$Q = 0$

## 1-11 ~ 1-15
All strings are rotationally identical

$Q = 0$

## 1-16 ~ 1-20
$Q = 0$ (subtask 1+2?)

## 1-21 ~ 1-30
Insertion only (should have worked like the previous one)

## 1-31 ~ 1-40
Deletion only with all strings being rotationally identical

## 1-41 ~ 1-50
Deletion only

## 1-51 ~ 1-60
Complete deletion (string set cleared)

## 1-61
Overflow check

# 2
Random small testcases

$N = 10$

$Q = 30$

$M = 3$

In the following, $p_{r}$ means the probability for generating a rotationally identical string when initialization or insertion, and $p_{d}$ means the probability for an operation to be deletion (insertion otherwise)

## 2-01 ~ 2-50
$p_{r} = p_{d} = 0.5$

## 2-51 ~ 2-75
$p_{r} = 0.5,\;p_{d} = 0.2$ (set growing)

## 2-76 ~ 2-99
$p_{r} = 0.7,\;p_{d} = 0.8$ (set shrinking)

# 3 (Subtask 1)
$N = Q = M = 50$

## 3-01 ~ 3-10
$p_{r} = 0.2,\;p_{d} = 0.6$

## 3-11 ~ 3-20
$p_{r} = 0.7,\;p_{d} = 0.6$

# 4 (Subtask 2)
$Q = 0$

$NM \approx 10 ^{6}$

## 4-01 ~ 4-02
all strings rotationally identical

### 4-01
$N = 10^{6}$

$M = 1$
### 4-02
$N = 5\times10^{5}$

$M = 2$

## 4-03 ~ 4-04
$N = 2$

$M = 5\times10^{5}$

### 4-03
rotationally identical
### 4-04
not rotationally identical

## 4-05 ~ 4-08
$2 \leq M \leq 5$

$p_{r} = 0.0005$

## 4-09 ~ 4-20
$p_{r} = 0.5$

# 5 (Subtask 3)
$M = 3$

$N+Q \approx 33333$

## 5-01 ~ 5-06
Insertion only

### 5-01 ~ 5-02
$p_{r} = 0.9995$
### 5-03 ~ 5-04
$p_{r} = 0.0005$
### 5-05 ~ 5-06
$p_{r} = 0.5$

## 5-07 ~ 5-10
Complete Deletion

## 5-11 ~ 5-15
$p_{d} = 0.5$