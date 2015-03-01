include gcc-gba.mk

#---------------------------------------------------
#���һЩĪ������Ķ���
.SUFFIXES:
#---------------------------------------------------

A_SRC	:= a.c \
			b.c
			
A_BIN	:= $(A_SRC:.c=.bin)
A_O		:= $(A_SRC:.c=.o)



.PHONY:all

all:$(A_BIN)
	@echo ����$(<)�ɹ�


%.o:%.c
	$(CC) $(CFLAGS) -c $< -o $@


%.bin:%.o
	$(OBJCOPY) -j.data -O binary $(<) $@



