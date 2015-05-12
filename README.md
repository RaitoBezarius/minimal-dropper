# minimal-dropper
This project is an attempt to make the most minimal portable dropper and try to see how can we counter it.

## Features ##
* [x] Ability to use libc functions dynamically (dlopen & dlsym).
* [ ] Silent crash without any `exit` / `ExitProcess` function. (Really hard :D).
* [ ] Portability: 
    * [x] BSD
    * [x] Linux 
    * [ ] OS X 
    * [ ] Windows
* [ ] Minimal linkage:
    * [ ] libc removed
    * [ ] CRT removed
    * [ ] system libs removed
    * [ ] misc
* [ ] Anti-detection measures:
    * [ ] Memory encryption (website target & payload content)
    * [ ] Anti-forensic (no disk write)
    * [ ] Anti-hook (detect tampered functions)
    * [ ] Anti-signature (dynamic code generation based on various parameters)
* [ ] Optionals micro-libs to download over the initialization of the program (like micro plugins)
* [ ] Start the payload without writing it on the disk using some obscure ways (RunPE style)
* Size as now: 8 Kib
