PREFIX	:= arm-none-eabi-

export 	CC		:= 	$(PREFIX)gcc
export	LD		:= 	$(PREFIX)ld
export AS		:=	$(PREFIX)as
export OBJCOPY	:= $(PREFIX)objcopy


ARCH	:= -mthumb 

export CFLAGS	:=	-O2 \
			-mcpu=arm7tdmi \
			-mabi=apcs-gnu \
			-nostdlib \
			$(ARCH)
