Script started on Sun 06 Mar 2016 10:56:45 PM PST
]0;bvarg006@hammer:~/CS100/assignments/rshell[?1034h[bvarg006@hammer rshell]$ bin/rshe;[Kll
bvarg006@hammer.cs.ucr.edu$ test bin
(True)
bvarg006@hammer.cs.ucr.edu$ test -f bin
(False)
bvarg006@hammer.cs.ucr.edu$ test -d bin
(True)
bvarg006@hammer.cs.ucr.edu$ test -e bin
(True)
bvarg006@hammer.cs.ucr.edu$ test sdfsdfsd
(False)
bvarg006@hammer.cs.ucr.edu$ [ -f sdfsd ]
(False)
bvarg006@hammer.cs.ucr.edu$ [ -d sdfsdfd ]
(False)
bvarg006@hammer.cs.ucr.edu$ [ -e sdfsdf ]
(False)
bvarg006@hammer.cs.ucr.edu$ [ -f bin ]
(False)
bvarg006@hammer.cs.ucr.edu$ [ -d bin ]
(True)
bvarg006@hammer.cs.ucr.edu$ [ -e bin ]
(True)
bvarg006@hammer.cs.ucr.edu$ l clear
[H[2Jbvarg006@hammer.cs.ucr.edu$ [ -e bin ] && ls
(True)
Segmentation fault
]0;bvarg006@hammer:~/CS100/assignments/rshell[bvarg006@hammer rshell]$ make clean
rm -rf bin
]0;bvarg006@hammer:~/CS100/assignments/rshell[bvarg006@hammer rshell]$ ls[K[Kmake
g++ -Wall -Werror -ansi -pedantic  src/main.cpp -o rshell
clearmkdir bin
mv rshell bin
]0;bvarg006@hammer:~/CS100/assignments/rshell[bvarg006@hammer rshell]$ clear
[H[2J]0;bvarg006@hammer:~/CS100/assignments/rshell[bvarg006@hammer rshell]$ bin/rshell
bvarg006@hammer.cs.ucr.edu$ ech   test &&   -e bin && ls
(True)
bin  LICENSE  Makefile	README.md  src	tests
bvarg006@hammer.cs.ucr.edu$ test dfsd && ls
(False)
bvarg006@hammer.cs.ucr.edu$ test fsd || ls
(False)
bin  LICENSE  Makefile	README.md  src	tests
bvarg006@hammer.cs.ucr.edu$ test bin || sdf   ls
(True)
bvarg006@hammer.cs.ucr.edu$ ( test -e bin && ech  o hi ) && (e echo a || echo b)
(True)
hi
a
bvarg006@hammer.cs.ucr.edu$ ( ls && (test bin || date ) )
bin  LICENSE  Makefile	README.md  src	tests
(True)
bvarg006@hammer.cs.ucr.edu$ ( ls || ( test bin && date ))^[[D^[[D                  # date      ; date ) )
bin  LICENSE  Makefile	README.md  src	tests
bvarg006@hammer.cs.ucr.edu$ test 
bvarg006@hammer.cs.ucr.edu$ test
bvarg006@hammer.cs.ucr.edu$ exi   test bin && exit
(True)
]0;bvarg006@hammer:~/CS100/assignments/rshell[bvarg006@hammer rshell]$ exit

Script done on Sun 06 Mar 2016 11:00:30 PM PST
