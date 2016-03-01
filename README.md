### rshell
`rshell` imitates the functionality of a bash terminal. `rshell` performs the following steps:

##### Assignment 1

1. Prints the command prompt with the user's username`<userName>@<hostName> $` 
2. Read in a command(s) on one line. Commands can be separated by connectors.
	- Arguements are separated by spaces.
	- Connectors include `;`, `&&`, `||`, and `#`.
	- Able to mix and match connectors and commands and still logically work.
3. Execute the line of commands
	- If a command is followed by `;`, then the next command is always executed.
	- If a command is followed by `&&`, then the next command is executed only if the first one succeeds.
	- If a command is followed by `||`, then the next command is executed only if the first one does not succeed.
	- Anything found after the first found `#` is considered a comment will not be passed through the terminal.

##### Bugs(Assignment 1)

1. cd: This alone other built-in bash commands will not work due to the fact that they have no executable file in the bin
2. exit: Sometimes requires to be input 2-4 times. Functionality works, just this bug was observed enough times 
3. &&: Sometimes when and || is based in the sequence false || true && , and && after this do not get run.
4. echo: when doing echo "[connectot]" nothing is output, echo " [anything else]" works as expected
5. Massive sequences of || (5>) with all except last returning false will return the last || as false in cases
6. Error comes up on first input in the command line. Works fine after that

##### How To Run rshell
```
$ git clone https://github.com/samhwangg/rshell.git
$ cd rshell
$ git checkout hw1
$ make
$ bin/rshell
```
test
