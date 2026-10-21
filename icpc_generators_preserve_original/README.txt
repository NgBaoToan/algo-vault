ICPC Testcase Builder — Windows & Linux
======================================

original_user.cpp       : Original user code, copied without any changes. May not compile as-is.
make_tests_windows.cpp  : Windows version, based on original structure.
make_tests_linux.cpp    : Linux/Ubuntu version, based on original structure.

Both tools require two separate executables for the task "FINDK1":
    gen_FINDK1    - input generator, writes FINDK1.inp
    FINDK1        - solution, reads FINDK1.inp and writes FINDK1.out

Default GENERATOR_USES_FILE_IO=true assumes generator uses freopen("FINDK1.inp", "w", stdout).
If your generator uses cout instead, set GENERATOR_USES_FILE_IO=false.
For the solver, both freopen() and cin/cout are supported via input/output redirection.

Ubuntu:
    g++ -std=c++17 -O2 gen_FINDK1.cpp -o gen_FINDK1
    g++ -std=c++17 -O2 FINDK1.cpp -o FINDK1
    g++ -std=c++17 -O2 make_tests_linux.cpp -o make_tests
    ./make_tests

Windows (MinGW g++):
    g++ -std=c++17 -O2 gen_FINDK1.cpp -o gen_FINDK1.exe
    g++ -std=c++17 -O2 FINDK1.cpp -o FINDK1.exe
    g++ -std=c++17 -O2 make_tests_windows.cpp -o make_tests.exe
    make_tests.exe

When prompted, enter:
    Input taskname: FINDK1
    Input startTest: 1
    Input endTest: 10

Generated:
    TEST001/FINDK1.inp, TEST001/FINDK1.out
    TEST002/FINDK1.inp, TEST002/FINDK1.out
    ...

IMPORTANT: .out comes from FINDK1 solution, so it is not necessarily correct without independent validation.
The Windows version has not been compiled or executed on Windows in this environment.
