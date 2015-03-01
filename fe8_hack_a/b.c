/*
 * b.c
 *
 *  Created on: 2015年2月24日
 *      Author: yimi
 */


#include "support.h"
#include "types.h"


#define SHOW_MAP_BASE 0x2003C14
#define SHOW_MAP(x) (u8*)(SHOW_MAP_BASE + ((x)*8))

#ifndef _MEM_BASE
//定义增加的属性,因为原内存没有那么多容量
#define _MEM_BASE 0x2010000
#endif
#define	_SHOW_MAP_P(x) (u8*)(_MEM_BASE + ((x)*8))


#define _MAP_BASE 0x2003D2C


#define _MAP_ADDR_(x,y)	(u8*)((((y)*0x20+(x))*2)+_MAP_BASE)



//武器文本索引指针
#define wt1	0x8A732A0
#define wt2 0x8A732A4
#define wt3 0x8A732A8
#define wt4 0x8A732AC

#define wt5 0x8A732B0
#define wt6 0x8A732B4
#define wt7 0x8A732B8
#define wt8 0x8A732BC

#define wt(x) (u8*)(0x8A732A0 + (x*4))


typedef struct{
		u8*		u0_;
		u8*		u4_;				//图层的tile属性,包括武器武器文字
		u8		u8_;				//调色板
		u8		u9_;				//坐标小偏移
		u16		uA_;
		u8*		uC_;				//武器文本索引
}st_80890BC;


//说明
//SHOW_MAP(x) 对应a.c文件的SHOW_MAP(x),
//a.c中的源码是要显示的宽度
//b.c的源码是要显示的文字

//想要添加显示的文字,以_SHOW_MAP_P(x)
//其中的x要不重复

//_MAP_ADDR_(x,y)
//这个是要显示的位置,
//x:以中间偏移X*8的位置,
//y:以2+(y*8)的高度位置

//接下来的0,是调色板编号

//wt(x),可以更改指针,指向文本的索引编号

st_80890BC m[]={
		{SHOW_MAP(25),_MAP_ADDR_(4,1),0,0,0,wt(5)},
		{SHOW_MAP(26),_MAP_ADDR_(4,3),0,0,0,wt(6)},
		{SHOW_MAP(27),_MAP_ADDR_(4,5),0,0,0,wt(7)},
		{SHOW_MAP(28),_MAP_ADDR_(4,7),0,0,0,wt(4)},

		{_SHOW_MAP_P(0),_MAP_ADDR_(4,9),0,0,0,wt(0)},
		{_SHOW_MAP_P(1),_MAP_ADDR_(4,11),0,0,0,wt(1)},
		{_SHOW_MAP_P(2),_MAP_ADDR_(4,13),0,0,0,wt(2)},
		{_SHOW_MAP_P(3),_MAP_ADDR_(4,15),0,0,0,wt(3)},


		{0,0,0,0,0,0}
};
