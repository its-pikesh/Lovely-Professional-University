# How to compile and run named pipes?

Open command line and enter
```commandline
gcc -o 1 create_named_pipe_fifo.c
./1
gcc -o 2 write2named_pipe.c
gcc -o 3 read_from_named_pipe.c
./2 & ./3
```
