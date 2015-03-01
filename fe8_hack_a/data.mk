include gcc-gba.mk

#---------------------------------------------------
#清除一些莫名其妙的东西
.SUFFIXES:
#---------------------------------------------------

A_SRC	:= a.c \
			b.c
			
A_BIN	:= $(A_SRC:.c=.bin)
A_O		:= $(A_SRC:.c=.o)



.PHONY:all

all:$(A_BIN)
	@echo 生成$(<)成功


%.o:%.c
	$(CC) $(CFLAGS) -c $< -o $@


%.bin:%.o
	$(OBJCOPY) -j.data -O binary $(<) $@



