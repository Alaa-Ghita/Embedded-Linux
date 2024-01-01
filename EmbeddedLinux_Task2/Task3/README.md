# Embedded Linux Task 3

Under the x-tools directory we have a folder for each compiler we have built using crosstool-ng, each one of them named after the target we build it for. Under each directory of them we have 2 main folders, bin folder and another folder with the name of the target.

## Sysroot 

The sysroot directory contains the basic files and directories that will be in the root of the target, including all the libraries that we have configured before building the compiler. 

## Binutils

The bin utilities are the binaries of the compiler commands we have configured before the building process. We can find them in the directory called bin after opening the the main directory of the compiler in the x-tools directory. These Binaries only deal with files the execute on the target only, but the bin utilities themselves can either be executables on the target only or on our machine only(ex. x86) based on either we build the compiler as Native or Cross Compiler   