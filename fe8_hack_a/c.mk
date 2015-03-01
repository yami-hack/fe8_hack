include gcc-gba.mk



C_DIR	:=	./c
C_SRC	:=	$(C_DIR)/c.c \
			$(C_DIR)/link.c

C_O		:=	$(C_SRC:.c=.o)
C_OUT	:=	c.out
			
C_BIN	:=	c.bin

LDS		:=	$(C_DIR)/c.ld

LDFLAGS	:=	-T$(LDS) \
			-nostdlib
			
OBJCOPYFLAGS	:=	-O binary \
					-R .link

.PHONY:all

all:$(C_BIN)
	@echo 创建 $< 成功

$(C_OUT):$(C_O)
	$(LD) $(LDFLAGS) $^ -o $@

$(C_BIN):$(C_OUT)
	$(OBJCOPY) $(OBJCOPYFLAGS) $< $@
