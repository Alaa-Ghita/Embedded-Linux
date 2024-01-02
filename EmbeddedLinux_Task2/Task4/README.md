# Why we use static libraries in AVR applications over dynamic libraries?

Dynamic libraries get linked to the application during the runtime, this needs a system loader to find the library in the ROM and load it to the RAM when the application is running and calling for this library. The system loader uses the memory management system (MMS) to load the applications and libraries into the RAM to get executed. Besides, the system loader needs an operating system (Kernal) running over the target machine in order for it to run and load anything into the RAM.

AVR micro-controllers  don't have any MMS units and mostly they can't run an OS. Thus, using static libraries is more suitable for this target machines.