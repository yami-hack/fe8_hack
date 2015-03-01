ROM		:=	bb.gba

MKS		:=	data.mk \
			c.mk

WRITE	:=	gba_write

MKFLAGS	:=	#-n




.PHONY:all clean write $(MKS)

#include c.mk
#include data.mk

all:$(MKS)
	@echo ���ɳɹ�
	
$(MKS):
	make -C ./ -f $@ $(MKFLAGS)
	@echo $@ ����ɹ�

clean:
	-rm a.bin b.bin c.bin a.o b.o c.out
	
#------------------------------------------------------------------
#����д���ַ

#����a.bin�ĵ�ַ,���޸�ֵ 0x08000000~0x09FFFFFF,��ROM��ָ��
A_BIN_ADDR		:= 0x09000000
B_BIN_ADDR		:= 0x081F543C
C_BIN_ADDR		:= 0x08089AC4
A_POINT_ADDR	:= 0x080890B8		#����ָ��ָ��0x09000000

#����������ƫ��ֵ,Խ��,����ͼ���������
W_X_			:= 2
W_X_COORD		:= 0x08089A70:1


#-------------------------------------------------------------------
	
write:
	@echo д�� $(ROM) 
	$(WRITE)	-F $(ROM) $(A_BIN_ADDR) a.bin
	$(WRITE)	-F $(ROM) $(B_BIN_ADDR) b.bin
	$(WRITE)	-F $(ROM) $(C_BIN_ADDR) c.bin
	$(WRITE)	-H $(ROM) $(A_POINT_ADDR) $(A_BIN_ADDR)
	$(WRITE)	-H $(ROM) $(W_X_COORD) $(W_X_)
	@echo д��ɹ�!
	
