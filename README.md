# minimal-dropper
This project is an attempt to make the most minimal portable dropper.

## Features ##
* No CRT/STL/GCC/bloatthing libs included. 
* Portable (Windows support soon)
* Can download file and make it run without writing it in the memory. (a sort of RunPE universal method)
* Encryption support on the fly?

## Current status ##
A lot of features listed are not ready or even in progress, so consider it as a TODO list more than Features list. :D
There is a minimal linux binary (460 bytes for a simple printf "Hey!", I don't know if this is the best I can do!)
I plan to add heap allocation (`malloc` and `free`), and `FILE*` stream-like interface.
After that, implement a simple download operation using the interface.
Then, either write the binary on the disk or fork/execute it from the memory.
