Script started on Sun 06 Mar 2016 10:18:57 PM PST
]0;bvarg006@hammer:~/CS100/assignments/rshell[?1034h[bvarg006@hammer rshell]$ bin/rshell
bvarg006@hammer.cs.ucr.edu$ test bin
(True)
bvarg006@hammer.cs.ucr.edu$ test -f bin
(False)
bvarg006@hammer.cs.ucr.edu$ test -e bin
(True)
bvarg006@hammer.cs.ucr.edu$ test -d bin
(True)
bvarg006@hammer.cs.ucr.edu$ [ -f in  bin ]
(False)
bvarg006@hammer.cs.ucr.edu$ [ -e bin ]
(True)
bvarg006@hammer.cs.ucr.edu$ [ -d bin ]
(True)
bvarg006@hammer.cs.ucr.edu$ [ -e sdfsd ]
(False)
bvarg006@hammer.cs.ucr.edu$ bin   test sdfsdf
(False)
bvarg006@hammer.cs.ucr.edu$ clear
[H[2Jbvarg006@hammer.cs.ucr.edu$ test if Make       -f Makefile && echo exists
(True)
exists
bvarg006@hammer.cs.ucr.edu$ test id M    -d Makefile &&  || echo no exist
(False)
no exist
bvarg006@hammer.cs.ucr.edu$ echo hiiii # test lol
hiiii
bvarg006@hammer.cs.ucr.edu$ echo hii || test sdfsd
hii
bvarg006@hammer.cs.ucr.edu$ echo hi test s      ; test sdfsdfsd
hi
(False)
bvarg006@hammer.cs.ucr.edu$ echo hi || (test -f Makefile && cal && cal)
hi
     March 2016     
Su Mo Tu We Th Fr Sa
       1  2  3  4  5
[7m 6[27m  7  8  9 10 11 12
13 14 15 16 17 18 19
20 21 22 23 24 25 26
27 28 29 30 31

     March 2016     
Su Mo Tu We Th Fr Sa
       1  2  3  4  5
[7m 6[27m  7  8  9 10 11 12
13 14 15 16 17 18 19
20 21 22 23 24 25 26
27 28 29 30 31

bvarg006@hammer.cs.ucr.edu$ echo hi && (test -f && Make       Makefile && cal && cal)
hi
(True)
bvarg006@hammer.cs.ucr.edu$ e ls
bin  LICENSE  Makefile	README.md  src	tests
bvarg006@hammer.cs.ucr.edu$ clear
[H[2Jbvarg006@hammer.cs.ucr.edu$ ex  ( test bin && echo exist) || (test hi && ls )
(True)
exist
bin  LICENSE  Makefile	README.md  src	tests
bvarg006@hammer.cs.ucr.edu$ exit
]0;bvarg006@hammer:~/CS100/assignments/rshell[bvarg006@hammer rshell]$ clear
[H[2J]0;bvarg006@hammer:~/CS100/assignments/rshell[bvarg006@hammer rshell]$ exit

Script done on Sun 06 Mar 2016 10:22:38 PM PST
