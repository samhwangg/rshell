Script started on Thu 11 Feb 2016 09:04:49 PM PST
]0;bvarg006@hammer:~/CS100/rshell[?1034h[bvarg006@hammer rshell]$ bin/rshell
bvarg006@hammer.cs.ucr.edu$ exit
]0;bvarg006@hammer:~/CS100/rshell[bvarg006@hammer rshell]$ bin/rshell
bvarg006@hammer.cs.ucr.edu$ echo exit wont run || exit
exit wont run
bvarg006@hammer.cs.ucr.edu$ echo t exit will run && exit
exit will run
]0;bvarg006@hammer:~/CS100/rshell[bvarg006@hammer rshell]$ bin/rshell
bvarg006@hammer.cs.ucr.edu$ ls #e  cal ; date ; exit
Error: Syntax
bvarg006@hammer.cs.ucr.edu$ ls # cal ; date l   ;e ex     exit
bin  LICENSE  Makefile	README.md  src	tests
bvarg006@hammer.cs.ucr.edu$ clear
[H[2Jbvarg006@hammer.cs.ucr.edu$ date ; date ; date ; exit
Thu Feb 11 21:06:34 PST 2016
Thu Feb 11 21:06:34 PST 2016
Thu Feb 11 21:06:34 PST 2016
]0;bvarg006@hammer:~/CS100/rshell[bvarg006@hammer rshell]$ bin/rshell
bvarg006@hammer.cs.ucr.edu$ echo hi && date || cal ; exit
Error: Syntax
bvarg006@hammer.cs.ucr.edu$ echo hi && date || cal ; exit
hi
Thu Feb 11 21:07:28 PST 2016
]0;bvarg006@hammer:~/CS100/rshell[bvarg006@hammer rshell]$ exit

Script done on Thu 11 Feb 2016 09:07:33 PM PST
