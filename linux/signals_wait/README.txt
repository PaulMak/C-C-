This program demonstrates using signals between processes

proc_1 is the process which waits for SIGUSR1 signal and terminates after receiving it.

proc_2 is the process which sends SIGUSR1 to process specified in its argument list.
returns 3

main program spawns proc_1 with PID of proc_2 and prints return status of child process ( 3 )