# Performance Analysis with gprof

What is gprof?

gprof’s a tool from GNU made to check how fast C or C++ code runs. It tells you stuff like where time gets spent during execution
1. How much time gets used per task
2. How often every function gets triggered
- Figure out how functions link to one another

# Why use gprof?
Profiling helps you:
Figure out what bits of your script take forever to run
Get how deep recursion goes - also see how functions call each other.
Check if theory matches actual results from tests

# Basic gprof Commands

1. Put together while turning on tracking

g++ -pg your_program.cpp -o your_program

2. Run your program

3. View profiling output:
gprof your_program gmon.out