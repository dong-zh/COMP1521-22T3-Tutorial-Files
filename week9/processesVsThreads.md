# What's the Difference Between Processes and Threads?

## Processes

- Processes contain threads of execution
- Each process essentially lives in its own little world
- Processes are isolated, they can't talk to other processes unless using features like through pipes, signals, the file system, etc.
- Context switching between processes is expensive
- You can think of 2 different processes as 2 programs doing different things, e.g. Steam and VS Code are doing their own thing, and have nothing to do with each other

## Threads

- Multiple threads of execution can exist within a process
- Threads in a process all share the same address space, so it's easy to communicate between them
- Context switching between threads in the same process is less expensive than switching between processes
- You can think of threads in the same process are a program doing 2 things at once, e.g. VS Code might have a thread for updating the screen while another thread syncs my settings to the cloud, or a game might have a thread for updating the physics engine while another thread plays the in-game sounds
