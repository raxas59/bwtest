# bwtest
Memory Bandwidth test
Memory bandwidth test per https://en.algorithmica.org/hpc/cpu-cache/bandwidth/
test has two parameters - number of operations, and iteration count
runtest.py fixes the total number of ops at 1 trillion. It starts off with 1024 ops, and doubles ops after every run.
