Script started on Sun 06 Mar 2016 11:50:51 PM PST
]0;bvarg006@hammer:~/CS100/assignments/rshell[?1034h[bvarg006@hammer rshell]$ ls
[0m[01;34mbin[0m  LICENSE  Makefile  README.md  [01;34msrc[0m  [01;34mtests[0m
[m]0;bvarg006@hammer:~/CS100/assignments/rshell[bvarg006@hammer rshell]$ bin/rshekll[K[K[Kll
bvarg006@hammer.cs.ucr.edu$ (echo a && echo b ) && (echo c && ) echo D )
a
b
c
D
bvarg006@hammer.cs.ucr.edu$ ec  (c echo A && echo B) || (echjo  o c && echo d)
A
B
d
bvarg006@hammer.cs.ucr.edu$ ls
bin  LICENSE  Makefile	README.md  src	tests
bvarg006@hammer.cs.ucr.edu$ clear
[H[2Jbvarg006@hammer.cs.ucr.edu$ (ls)
bin  LICENSE  Makefile	README.md  src	tests
bvarg006@hammer.cs.ucr.edu$ ( ls || date)
bin  LICENSE  Makefile	README.md  src	tests
bvarg006@hammer.cs.ucr.edu$ ls  ) (ls || date ) && cal
bin  LICENSE  Makefile	README.md  src	tests
bvarg006@hammer.cs.ucr.edu$ cal ( ls || date)
cal: illegal year value: use 1-9999
bvarg006@hammer.cs.ucr.edu$ cal || (    ; (ls || date)
     March 2016     
Su Mo Tu We Th Fr Sa
       1  2  3  4  5
[7m 6[27m  7  8  9 10 11 12
13 14 15 16 17 18 19
20 21 22 23 24 25 26
27 28 29 30 31

bin  LICENSE  Makefile	README.md  src	tests
bvarg006@hammer.cs.ucr.edu$ cal 345 && (who || cal)
                                345                               

       January               February                 March       
Su Mo Tu We Th Fr Sa   Su Mo Tu We Th Fr Sa   Su Mo Tu We Th Fr Sa
       1  2  3  4  5                   1  2                   1  2
 6  7  8  9 10 11 12    3  4  5  6  7  8  9    3  4  5  6  7  8  9
13 14 15 16 17 18 19   10 11 12 13 14 15 16   10 11 12 13 14 15 16
20 21 22 23 24 25 26   17 18 19 20 21 22 23   17 18 19 20 21 22 23
27 28 29 30 31         24 25 26 27 28         24 25 26 27 28 29 30
                                              31
        April                   May                   June        
Su Mo Tu We Th Fr Sa   Su Mo Tu We Th Fr Sa   Su Mo Tu We Th Fr Sa
    1  2  3  4  5  6             1  2  3  4                      1
 7  8  9 10 11 12 13    5  6  7  8  9 10 11    2  3  4  5  6  7  8
14 15 16 17 18 19 20   12 13 14 15 16 17 18    9 10 11 12 13 14 15
21 22 23 24 25 26 27   19 20 21 22 23 24 25   16 17 18 19 20 21 22
28 29 30               26 27 28 29 30 31      23 24 25 26 27 28 29
                                              30
        July                  August                September     
Su Mo Tu We Th Fr Sa   Su Mo Tu We Th Fr Sa   Su Mo Tu We Th Fr Sa
    1  2  3  4  5  6                1  2  3    1  2  3  4  5  6  7
 7  8  9 10 11 12 13    4  5  6  7  8  9 10    8  9 10 11 12 13 14
14 15 16 17 18 19 20   11 12 13 14 15 16 17   15 16 17 18 19 20 21
21 22 23 24 25 26 27   18 19 20 21 22 23 24   22 23 24 25 26 27 28
28 29 30 31            25 26 27 28 29 30 31   29 30

       October               November               December      
Su Mo Tu We Th Fr Sa   Su Mo Tu We Th Fr Sa   Su Mo Tu We Th Fr Sa
       1  2  3  4  5                   1  2    1  2  3  4  5  6  7
 6  7  8  9 10 11 12    3  4  5  6  7  8  9    8  9 10 11 12 13 14
13 14 15 16 17 18 19   10 11 12 13 14 15 16   15 16 17 18 19 20 21
20 21 22 23 24 25 26   17 18 19 20 21 22 23   22 23 24 25 26 27 28
27 28 29 30 31         24 25 26 27 28 29 30   29 30 31


dzhan008 pts/0        2016-03-06 22:10 (66-215-155-235.dhcp.rvsd.ca.charter.com)
bvarg006 pts/1        2016-03-06 23:50
gocam001 pts/2        2016-03-06 22:42 (pool-173-51-88-82.lsanca.fios.verizon.net)
mpho001  pts/3        2016-03-06 21:37 (99-53-225-208.lightspeed.irvnca.sbcglobal.net)
hocho002 pts/4        2016-03-06 18:17 (cpe-142-129-205-123.socal.res.rr.com)
struo006 pts/5        2016-03-06 22:35 (63.138.45.36)
kcole002 pts/6        2016-03-06 23:09 (mothership.dyn.ucr.edu)
bvarg006 pts/7        2016-03-06 21:26 (baldo.dyn.ucr.edu)
pgior001 pts/8        2016-03-06 23:10 (169.235.57.144)
pgior001 pts/10       2016-03-06 22:58 (169.235.57.144)
xzhua001 pts/12       2016-03-06 21:42 (66-215-13-82.static.gldl.ca.charter.com)
rlui001  pts/13       2016-03-06 16:54 (dhcp-138-23-65-161.dyn.ucr.edu)
mshen010 pts/14       2016-03-06 13:54 (75-142-199-194.static.rvsd.ca.charter.com)
swu038   pts/15       2016-03-06 22:11 (dhcp-138-23-65-161.dyn.ucr.edu)
hocho002 pts/21       2016-03-06 21:44 (cpe-142-129-205-123.socal.res.rr.com)
rlui001  pts/28       2016-03-06 16:22 (dhcp-138-23-65-161.dyn.ucr.edu)
bvarg006@hammer.cs.ucr.edu$ (exit    ls && (exit || echo hi))
bin  LICENSE  Makefile	README.md  src	tests
]0;bvarg006@hammer:~/CS100/assignments/rshell[bvarg006@hammer rshell]$ bin/rshell
bvarg006@hammer.cs.ucr.edu$ (echo bue   CS100 && echo b) ; exit
CS100
b
]0;bvarg006@hammer:~/CS100/assignments/rshell[bvarg006@hammer rshell]$ exit

Script done on Sun 06 Mar 2016 11:52:45 PM PST
