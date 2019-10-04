#Problem.3 Numberix
===================

**###1.Introduction** 


This program is for PA1-3 in Discrete Mathematics class (fall 2019).



**###2.Compile command** 


**chmod 755 build_script**


**./build_script**



To execute the build script file, we need a permission.
'chmod 755' command gives the permission,

The input file have to named as 'input.txt'.
Also you can handle each steps for compiling.

__gcc Problem3Solver.c


cat input.txt | ./a.out > Numbrix_solution.txt__

Output is saved in NumbrixSolution.txt



**###3.Standard Input** 


The maximum input size is '100x100'.
Unknown number have to be expressed by '?'.

All input values use standard input stream.
By using this, the program can get the user input.

**###4.Output**


The row and column number, input matrix(change '?' to '0') and the solution matrix are given.
If there is no solution, the program would print 'No solution!'statement.
