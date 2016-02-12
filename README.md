### rshell
`rshell` imitates the functionality of a terminal. `rshell` performs the following steps:

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

-
- 
- Add actual bugs here

##### How To Run rshell
```
$ git clone https://github.com/samhwangg/rshell.git
$ cd rshell
$ git checkout hw1
$ make
$ bin/rshell
```
