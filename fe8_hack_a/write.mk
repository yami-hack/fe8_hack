ROM		:=	bb.gba

MKS		:=	data.mk \
			c.mk

WRITE	:=	gba_write

MKFLAGS	:=	#-n




.PHONY:all clean write $(MKS)

#include c.mk
#include data.mk

all:$(MKS)
	@echo 生成成功
	
$(MKS):
	make -C ./ -f $@ $(MKFLAGS)
	@echo $@ 编译成功

clean:
	-rm a.bin b.bin c.bin a.o b.o c.out
	
#------------------------------------------------------------------
#数据写入地址

#导入a.bin的地址,可修改值 0x08000000~0x09FFFFFF,是ROM的指针
A_BIN_ADDR		:= 0x09000000
B_BIN_ADDR		:= 0x081F543C
C_BIN_ADDR		:= 0x08089AC4
A_POINT_ADDR	:= 0x080890B8		#更改指针指向0x09000000

#熟练度条的偏移值,越大,则离图标距离做大
W_X_			:= 2
W_X_COORD		:= 0x08089A70:1


#-------------------------------------------------------------------
	
write:
	@echo 写入 $(ROM) 
	$(WRITE)	-F $(ROM) $(A_BIN_ADDR) a.bin
	$(WRITE)	-F $(ROM) $(B_BIN_ADDR) b.bin
	$(WRITE)	-F $(ROM) $(C_BIN_ADDR) c.bin
	$(WRITE)	-H $(ROM) $(A_POINT_ADDR) $(A_BIN_ADDR)
	$(WRITE)	-H $(ROM) $(W_X_COORD) $(W_X_)
	@echo 写入成功!
	
