# Description
This project aims to program a function that returns a line read from a file descriptor. A line is defined as a consecutive sequence of characters terminated by a newline '\n'. A null is returned if an error occurs or end of file is reached.


# Features
- handles invalid file descriptors
- can handle only 1 file descriptor at a time


# Instruction
1. create a file called main.c that loops through a file with a string ending with '\n'
2. cc -Wall -Wextra -Werror main.c get_next_line.c get_next_line_utils.c
3. run ./a.out


# Resources
stream & buffer - [reddit](https://www.reddit.com/r/C_Programming/comments/tuc2pl/i_need_help_understanding_streams_and_buffers_in_c/), [University of Michigan](https://websites.umich.edu/~eecs381/handouts/basicCio.pdf)
FILE structure, file descriptor, FCB - [ChatGPT](https://chatgpt.com/share/69b10deb-a9dc-8006-865e-2a9241facadd)
read(), detecting EOF and error - man read
Static variables - [geeksforgeeks](https://www.geeksforgeeks.org/c/static-variables-in-c/)
-D option for gcc - man gcc (line 13478)
stack & fd limits - [stackexchange](https://unix.stackexchange.com/questions/84227/limits-on-the-number-of-file-descriptors)
