# Poisson-Distributions
Computing Systems Fundamentals
CS 3360

This project contains solutions for two problems related to random number generation and system simulation using C++:

Files Included:
csfP1a.cpp: Source code for generating a workload of 1000 processes based on the given distributions.
csfP1b.cpp: Source code for simulating server failure and restoration times over 20 years.
README.txt: This file, explaining how to compile and run the programs.
reportCSFP1.pdf: A brief report summarizing the implementation and results of both problems.

Part 1: Generates a workload of 1000 processes, where the arrival rate follows a Poisson distribution, and the service time follows an Exponential distribution.

1. Connect to the Texas State Linux server using your credentials.
2. Upload the file using an SCP client.
3. Compile the file using the "g++ csfP1a.cpp" command.
4. You will then see a file named "a.out", run this file using the "./a.out" command. 

Part 2: Simulates the failure and restoration times of a computing system with two mirrored servers over a 20-year period. The goal is to determine how long it would take for the entire system to fail (both servers failing within the same 10-hour restoration window).

1. Connect to the Texas State Linux server using your credentials.
2. Upload the file using an SCP client.
3. Compile the file using the "g++ csfP1b.cpp" command.
4. You will then see a file named "a.out", run this file using the "./a.out" command. 
