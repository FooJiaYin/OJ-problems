## Prerequisite
- gcc

## Compile
```bash
cd p4
gcc p4_2.c -o a.exe
```

## Run on all testcase
```bash
./test.sh p4
```

## Run on single testcase
```bash
cd p4
./a.exe < testcase/sin/4-01.txt > out/4-01.txt
```

## Check output
```bash
./check.sh p4 > p4/result.txt
```
This will generate a file named `result.txt` which contains the result of all testcases.
