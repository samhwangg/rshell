Script started on Sun 06 Mar 2016 10:23:01 PM PST
]0;bvarg006@hammer:~/CS100/assignments/rshell[?1034h[bvarg006@hammer rshell]$ ls
LICENSE  Makefile  README.md  [0m[01;34msrc[0m  [01;34mtests[0m
[m]0;bvarg006@hammer:~/CS100/assignments/rshell[bvarg006@hammer rshell]$ make
g++ -Wall -Werror -ansi -pedantic  src/main.cpp -o rshell
mkdir bin
mv rshell bin
]0;bvarg006@hammer:~/CS100/assignments/rshell[bvarg006@hammer rshell]$ bin/rshell
bvarg006@hammer.cs.ucr.edu$ ls # gdfgdfddddddddddddddddddddddddd
bin  LICENSE  Makefile	README.md  src	tests
bvarg006@hammer.cs.ucr.edu$ ls && echo hi ;   # sdfsdbkfjsdhfsdfsdfsd
bin  LICENSE  Makefile	README.md  src	tests
hi
bvarg006@hammer.cs.ucr.edu$ (echo hi && ls) # (ls ||d  date )
hi
bin  LICENSE  Makefile	README.md  src	tests
bvarg006@hammer.cs.ucr.edu$ echo    ( echo hi && ls && (date # ls))
hi
bin  LICENSE  Makefile	README.md  src	tests
Sun Mar  6 22:24:03 PST 2016
bvarg006@hammer.cs.ucr.edu$ ls && (date || ca  l && cal # sdfsdfsdfsd ( || ls     || ls ) )^[[D             echo hi || ls ) )
Error: Paranthesis do not match.
bvarg006@hammer.cs.ucr.edu$ ls && (date || cal # cal )
Error: Paranthesis do not match.
bvarg006@hammer.cs.ucr.edu$ # sdfffffff ( SF)SD FSD FSD)F)SDF(SDF)SD
bvarg006@hammer.cs.ucr.edu$ ls
bin  LICENSE  Makefile	README.md  src	tests
bvarg006@hammer.cs.ucr.edu$ clear
[H[2Jbvarg006@hammer.cs.ucr.edu$ (echo a && b) &&     ls ) # sdfsdfsdfsdfsdjkfbhsdjkfhsd
a
bin  LICENSE  Makefile	README.md  src	tests
bvarg006@hammer.cs.ucr.edu$ # (sdfsdfsdfsd
bvarg006@hammer.cs.ucr.edu$ clear
[H[2Jbvarg006@hammer.cs.ucr.edu$ ex  # exit
bvarg006@hammer.cs.ucr.edu$ # [ -f makesdf ]
bvarg006@hammer.cs.ucr.edu$ exit
]0;bvarg006@hammer:~/CS100/assignments/rshell[bvarg006@hammer rshell]$ exit

Script done on Sun 06 Mar 2016 10:26:16 PM PST
