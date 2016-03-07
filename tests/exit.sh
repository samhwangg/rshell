Script started on Sun 06 Mar 2016 10:27:44 PM PST
]0;bvarg006@hammer:~/CS100/assignments/rshell[?1034h[bvarg006@hammer rshell]$ ls
LICENSE  Makefile  README.md  [0m[01;34msrc[0m  [01;34mtests[0m
[m]0;bvarg006@hammer:~/CS100/assignments/rshell[bvarg006@hammer rshell]$ make
g++ -Wall -Werror -ansi -pedantic  src/main.cpp -o rshell
mkdir bin
mv rshell bin
]0;bvarg006@hammer:~/CS100/assignments/rshell[bvarg006@hammer rshell]$ bin/rshell
bvarg006@hammer.cs.ucr.edu$ exit
]0;bvarg006@hammer:~/CS100/assignments/rshell[bvarg006@hammer rshell]$ bin/rshell
bvarg006@hammer.cs.ucr.edu$ ls || exit
bin  LICENSE  Makefile	README.md  src	tests
bvarg006@hammer.cs.ucr.edu$ ls && exit
bin  LICENSE  Makefile	README.md  src	tests
]0;bvarg006@hammer:~/CS100/assignments/rshell[bvarg006@hammer rshell]$ bin/rshell
bvarg006@hammer.cs.ucr.edu$ ls && echo hi ; exit
bin  LICENSE  Makefile	README.md  src	tests
hi
]0;bvarg006@hammer:~/CS100/assignments/rshell[bvarg006@hammer rshell]$ bin/rshell
bvarg006@hammer.cs.ucr.edu$ ls && echo hi # exit
bin  LICENSE  Makefile	README.md  src	tests
hi
bvarg006@hammer.cs.ucr.edu$ (echo a && a echo b) || exit
a
b
bvarg006@hammer.cs.ucr.edu$ (echo a && echo b) && exit
a
b
]0;bvarg006@hammer:~/CS100/assignments/rshell[bvarg006@hammer rshell]$ bin/rshell
bvarg006@hammer.cs.ucr.edu$ # exit 
bvarg006@hammer.cs.ucr.edu$ (ls && ( echo hi || exit ) )
bin  LICENSE  Makefile	README.md  src	tests
hi
bvarg006@hammer.cs.ucr.edu$ ls && ( l date && (cal &&  || echo hi) ; exit) && cal   who
bin  LICENSE  Makefile	README.md  src	tests
Sun Mar  6 22:29:48 PST 2016
     March 2016     
Su Mo Tu We Th Fr Sa
       1  2  3  4  5
[7m 6[27m  7  8  9 10 11 12
13 14 15 16 17 18 19
20 21 22 23 24 25 26
27 28 29 30 31

]0;bvarg006@hammer:~/CS100/assignments/rshell[bvarg006@hammer rshell]$ bin/rshell
bvarg006@hammer.cs.ucr.edu$ who &&    || (echo a && exit )
dzhan008 pts/0        2016-03-06 22:10 (66-215-155-235.dhcp.rvsd.ca.charter.com)
dtara003 pts/1        2016-03-06 20:17 (71-95-19-85.static.rvsd.ca.charter.com)
smosh002 pts/2        2016-03-06 20:28 (63.138.45.36)
mpho001  pts/3        2016-03-06 21:37 (99-53-225-208.lightspeed.irvnca.sbcglobal.net)
hocho002 pts/4        2016-03-06 18:17 (cpe-142-129-205-123.socal.res.rr.com)
shwan022 pts/5        2016-03-06 20:54 (104.241.36.27)
kcole002 pts/6        2016-03-06 21:56 (mothership.dyn.ucr.edu)
bvarg006 pts/7        2016-03-06 21:26 (baldo.dyn.ucr.edu)
kmena003 pts/8        2016-03-06 20:14 (169.235.217.88)
nbatt002 pts/9        2016-03-06 21:41 (71-84-66-164.dhcp.rvsd.ca.charter.com)
struo006 pts/10       2016-03-06 19:53 (63.138.45.36)
rho003   pts/11       2016-03-06 19:46 (71-95-52-47.dhcp.rvsd.ca.charter.com)
xzhua001 pts/12       2016-03-06 21:42 (66-215-13-82.static.gldl.ca.charter.com)
rlui001  pts/13       2016-03-06 16:54 (dhcp-138-23-65-161.dyn.ucr.edu)
mshen010 pts/14       2016-03-06 13:54 (75-142-199-194.static.rvsd.ca.charter.com)
swu038   pts/15       2016-03-06 22:11 (dhcp-138-23-65-161.dyn.ucr.edu)
xduan001 pts/16       2016-03-06 22:05 (24-205-112-161.dhcp.hspr.ca.charter.com)
gocam001 pts/17       2016-03-06 21:43 (pool-173-51-88-82.lsanca.fios.verizon.net)
bvarg006 pts/18       2016-03-06 22:27
nnguy072 pts/19       2016-03-06 20:57 (nam-pc.dyn.ucr.edu)
atran049 pts/20       2016-03-06 19:27 (24-180-53-167.dhcp.rvsd.ca.charter.com)
hocho002 pts/21       2016-03-06 21:44 (cpe-142-129-205-123.socal.res.rr.com)
wsio001  pts/22       2016-03-06 22:22 (75-139-231-244.static.rvsd.ca.charter.com)
ktran050 pts/27       2016-03-06 19:56 (63.138.45.36)
rlui001  pts/28       2016-03-06 16:22 (dhcp-138-23-65-161.dyn.ucr.edu)
bvarg006@hammer.cs.ucr.edu$ clear
[H[2Jbvarg006@hammer.cs.ucr.edu$ exit
]0;bvarg006@hammer:~/CS100/assignments/rshell[bvarg006@hammer rshell]$ exit

Script done on Sun 06 Mar 2016 10:31:24 PM PST
