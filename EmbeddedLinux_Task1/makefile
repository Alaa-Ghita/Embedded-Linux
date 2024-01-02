CC = gcc
AR = ar

DynamicObjects  = DynamicLinking/addition.o
DynamicObjects += DynamicLinking/division.o
DynamicObjects += DynamicLinking/modulus.o 
DynamicObjects += DynamicLinking/multiplication.o
DynamicObjects += DynamicLinking/subtraction.o

StaticObjects  = ObjectFiles/addition.o
StaticObjects += ObjectFiles/division.o
StaticObjects += ObjectFiles/modulus.o 
StaticObjects += ObjectFiles/multiplication.o
StaticObjects += ObjectFiles/subtraction.o

Headers = Headerfiles/

LibName            = operation
StaticLibDir       = ~/Embedded-Linux/EmbeddedLinux_Task1/StaticLinking/
StaticLibFullName  = StaticLinking/liboperation.a
DynamicLibDir      = ~/Embedded-Linux/EmbeddedLinux_Task1/DynamicLinking/
DynamicLibName     = DynamicLinking/liboperation.so

AppSource        = main.c
AppStaticOutput  = StaticLinking/main.out
AppDynamicOutput = DynamicLinking/main.out

CFLAG       = -c
WALL_FLAG   = -Wall
OFLAG       = -o
IFLAG       = -I
GFLAG       = -g
RCS_FLAG    = -rcs
LFLAG       = -L
lFLAG       = -l
FPIC_FLAG   = -fPIC
STATIC_FLAG = -static
SHARED_FLAG = -shared

#Static Linking
$(AppStaticOutput) : $(AppSource) $(AppDynamicOutput) $(StaticLibName) 
	$(CC) $(STATIC_FLAG) $< $(LFLAG) $(StaticLibDir) $(lFLAG) $(LibName) $(IFLAG) $(Headers) $(OFLAG) $@
	
$(StaticLibName) : $(StaticObjects)
	$(AR) $(RCS_FLAG) $@ $^
	
$(StaticObjects) : ObjectFiles/%.o : SourceFiles/%.c
	$(CC) $(CFLAG) $< $(OFLAG) $@ $(IFLAG) $(Headers)

. PHONY : cleanStatic cleanDynamic BuildStatic BuildDynamic

cleanStatic :
	rm $(AppStaticOutput) $(StaticObjects) $(StaticLibName)

#Dynamic Linking
$(AppDynamicOutput) : $(AppSource) $(DynamicLibName)
	$(CC) $(SHARED_FLAG) $< $(LFLAG) $(DynamicLibDir) $(lFLAG) $(LibName) $(IFLAG) $(Headers) $(OFLAG) $@
	export LD_LIBRARY_PATH=$(DynamicLibDir)
	
$(DynamicLibName) : $(DynamicObjects)
	$(CC) $(SHARED_FLAG) $(OFLAG) $@ $^
	
$(DynamicObjects) : DynamicLinking/%.o : SourceFiles/%.c
	$(CC) $(CFLAG) $(GFLAG) $(WALL_FLAG) $(FPICFLAG) $< $(OFLAG) $@ $(IFLAG) $(Headers)

cleanDynamic :
	rm $(AppDynamicOutput) $(DynamicObjects) $(DynamicLibName)
