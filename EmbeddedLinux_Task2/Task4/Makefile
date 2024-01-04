CC = ~/x-tools/avr/bin/avr-gcc
AR = ~/x-tools/avr/bin/avr-ar

SourcesList  =  Sources/PORT_cfg.c
SourcesList += Sources/PORT.c 
SourcesList += Sources/DIO_cfg.c 
SourcesList += Sources/DIO.c 
SourcesList += Sources/delay.c

ObjectsList  = Objects/PORT_cfg.o
ObjectsList += Objects/PORT.o
ObjectsList += Objects/DIO_cfg.o 
ObjectsList += Objects/DIO.o
ObjectsList += Objects/delay.o

Headers     = Headers/

LibDir      = ./lib/
LibName     = mcal
LibFullName = lib/libmcal.a

AppSource = main.c
AppOutput = main.elf

CFLAG      = -c
WALLFLAG   = -Wall
OFLAG      = -o
IFLAG      = -I
RCSFLAG    = -rcs
LFLAG      = -L
lFLAG      = -l
STATICFLAG = -static

$(AppOutput) : $(AppSource) $(LibFullName)
	@$(CC) -mmcu=atmega32 $(STATICFLAG) $< $(LFLAG) $(LibDir) $(lFLAG) $(LibName) $(IFLAG) $(Headers) $(OFLAG) $@
	
$(LibFullName) : $(ObjectsList)
	@$(AR) $(RCSFLAG) $@ $^
	
$(ObjectsList) : Objects/%.o : Sources/%.c
	@$(CC) $(CFLAG) $(WALLFLAG) $< $(OFLAG) $@ $(IFLAG) $(Headers)
	
.PHONY : clean 

clean :
	@rm $(AppOutput) $(ObjectsList) $(LibFullName)
