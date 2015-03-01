

SECTIONS{
	_80890BC = 0x80890BC;
	_8089910 = 0x8089910;
	_8089A00 = 0x8089A00;
	
	. = 0x8089AC4;
	.text : 
	{
		KEEP (*(EXCLUDE_FILE (*link.o) .text))
	}
	
	.link : 
	{
		*link.o(.text)
	}
}

