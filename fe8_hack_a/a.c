/*
 * a.c
 *
 *  Created on: 2015年2月24日
 *      Author: yimi
 */

#include "types.h"
#include "support.h"



typedef struct{
	u8*		u0_;			//show_map属性设置
	u8		u4_;			//宽度
	u8		u5_;			//内置
	u8		u6_;			//内置
	u8		u7_;			//内置asd
}tm8A727B4	;




#ifndef _MEM_BASE
//定义增加的属性,因为原内存没有那么多容量
#define _MEM_BASE 0x2010000
#endif



#define	_SHOW_MAP_P(x) (u8*)(_MEM_BASE + ((x)*8))


#define SHOW_MAP(x)	(u8*)(0x2003C14 + (x*8))


tm8A727B4	m8A727B4[]	=	{

		{SHOW_MAP(0),7},	//02003C14,名字的显示宽度
//其中的SHOW_MAP(0),	是显示的第一个属性,不更改最好
//其中的 7,				是显示的宽度

		{SHOW_MAP(1),7},	//职业的显示宽度

		{SHOW_MAP(2),3},//02003C24

		//以下,分别是,力量,技术,速度,幸运,守备,魔防,移动,
		//体格,救出
		{SHOW_MAP(3),3},
		{SHOW_MAP(4),3},//02003C34
		{SHOW_MAP(5),3},
		{SHOW_MAP(6),3},//02003C44
		{SHOW_MAP(7),3},
		{SHOW_MAP(8),3},//02003C54
		{SHOW_MAP(9),3},
		{SHOW_MAP(10),3},//02003C64


		{SHOW_MAP(11),3},

		{SHOW_MAP(12),9},//02003C74,同行 ---
		{SHOW_MAP(13),7},//属性 XX
		{SHOW_MAP(14),9},//02003C84,状态 ---
		{SHOW_MAP(15),7},//

		{SHOW_MAP(16),7},//02003C94	物品1的名字
		{SHOW_MAP(17),7},//			物品2的名字
		{SHOW_MAP(18),7},//02003CA4 物品3的名字
		{SHOW_MAP(19),7},//			物品4的名字
		{SHOW_MAP(20),7},//02003CB4 物品5的名字

		{SHOW_MAP(21),3},			//攻击
		{SHOW_MAP(22),3},//02003CC4	必杀
		{SHOW_MAP(23),3},			//命中
		{SHOW_MAP(24),3},//02003CD4	回避

		//以下四个是武器文字的显示
		{SHOW_MAP(25),2},
		{SHOW_MAP(26),2},//02003CE4
		{SHOW_MAP(27),2},
		{SHOW_MAP(28),2},//02003CF4

		//以下是六个支援关系名字
		//去掉4个支援,以添加四个武器
		{SHOW_MAP(29),7},
		{SHOW_MAP(30),7},//02003D04
		{SHOW_MAP(31),7},
		{SHOW_MAP(32),7},//02003D14
		{SHOW_MAP(33),7},
		{SHOW_MAP(34),0x10},//02003D24

		//容量不够,所以注释掉下面4行
//		{SHOW_MAP(35),2},
//		{SHOW_MAP(36),2},
//		{SHOW_MAP(37),2},
//		{SHOW_MAP(38),2},
		{_SHOW_MAP_P(0),2},
		{_SHOW_MAP_P(1),2},
		{_SHOW_MAP_P(2),2},
		{_SHOW_MAP_P(3),2},

		{0,0}
};



