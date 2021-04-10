hasznos

hex miért szeretjök

0xF = 1111
1 byte = 2 helyiértéknyi hex szám
0xFF -> 1 bzte max méret
0x00 1 bájt 0

bitmanipuláció

bitwise and

0x01 & 0x0F -> 0x01
0000 0001 & 0000 1111 -> 0000 00001

bitwise or -> minden bitet ossze vagyolunk

0x01 | 0x0F -> 0x01
0000 0001 | 0000 1111 -> 0000 1111

shift 

left shift 

0000 0001 << 1 -> 0000 0010

Bit packing

0010 0110 -> 0x0F, 0xF0

transvoxel

high, low nibble

bitflag!

32 bool value van belerakva -> fizikai motor ütközés pl

vagy a dungeon impl


enum BuildFlags {
	BUILD_FLAG_USE_ISOLEVEL = 1 << 0, 
	BUILD_FLAG_USE_LIGHTING = 1 << 1, 
	BUILD_FLAG_USE_AO = 1 << 2,       
	BUILD_FLAG_USE_RAO = 1 << 3,
	BUILD_FLAG_GENERATE_AO = 1 << 4,
	BUILD_FLAG_AUTO_GENERATE_RAO = 1 << 5,
	BUILD_FLAG_BAKE_LIGHTS = 1 << 6,
	BUILD_FLAG_CREATE_COLLIDER = 1 << 7,
	BUILD_FLAG_CREATE_LODS = 1 << 8,
};

enum BuildFlags {
	BUILD_FLAG_USE_ISOLEVEL = 1 << 0, 0000 0001
	BUILD_FLAG_USE_LIGHTING = 1 << 1, 0000 0010
	BUILD_FLAG_USE_AO = 1 << 2,       0000 0100
	BUILD_FLAG_USE_RAO = 1 << 3,
	BUILD_FLAG_GENERATE_AO = 1 << 4,
	BUILD_FLAG_AUTO_GENERATE_RAO = 1 << 5,
	BUILD_FLAG_BAKE_LIGHTS = 1 << 6,
	BUILD_FLAG_CREATE_COLLIDER = 1 << 7,
	BUILD_FLAG_CREATE_LODS = 1 << 8,
};

0000 0011

BUILD_FLAG_USE_ISOLEVEL | BUILD_FLAG_USE_LIGHTING -> 0000 0011

0000 0011 & BUILD_FLAG_USE_ISOLEVEL != 0

egy intbe el tudunk tárolni sok boolt

Összead or, ellenőriz és


memória

valójában 1d!

a memóriachipek absztrakcióval el vannak rejtve -> memória controllerekkel -> (cpu kéri 0xFFaaf111 helyen lévő adatot) -> áramkör tudja-> mint egy objektum

64 bites os -> 64 bites int nagyságó cím

0x00 0x00 0x00 0x00 0x00 0x00 0x00
0x00 0x00 0x00 0x00 0x00 0x00 0x00
0x00 0x00 0x00 0x00 0x00 0x00 0x00
0x00 0x00 0x00 0x00 0x00 0x00 0x00
0x00 0x00 0x00 0x00 0x00 0x00 0x00
0x00 0x00 0x00 0x00 0x00 0x00 0x00
0x11 0xF1 0x11 0x12 0x12 0x11 0x33
0x11 0xF1 0x11 0x12 0x12 0x11 0x33
0x11 0xF1 0x11 0x12 0x12 0x11 0x33
0x11 0xA1 0x11 0x12 0x12 0x11 0x33
0x11 0xE1 0x11 0x12 0x12 0x11 0x33
0x11 0xA1 0x11 0x12 0x12 0x11 0x33
0x11 0xF1 0x11 0x12 0x12 0x11 0x33
0x11 0xF1 0x11 0x12 0x12 0x11 0x33
0x11 0xF1 0x11 0x12 0x12 0x11 0x33
0x11 0xF1 0x11 0x12 0x12 0x11 0x33
0x00 0x00 0x00 0x00 0x00 0x00 0x00
0x00 0x00 0x00 0x00 0x00 0x00 0x00
...

assembly

regiszter kép

rsp - >stack pointer
rbp -> is the frame pointer on  x86_64
it gets a snapshot of the stack pointer (rsp) so that when adjustments are made to rsp
(i.e. reserving space for local variables or pushing values on to the stack), local variables and function parameters are still accessible from a constant offset from rbp.

square(int): -> (label) memóriacím lessz
        push    rbp
        mov     rbp, rsp
        mov     DWORD PTR [rbp-4], edi
.L3:  
        cmp     DWORD PTR [rbp-4], 999
        jg      .L2
        add     DWORD PTR [rbp-4], 1
        jmp     .L3
.L2: 
        mov     eax, DWORD PTR [rbp-4]
        pop     rbp
        ret

0000 0011 -> instr

0x14 = push
0x11 = mov
0xF1 = jg
...

processzor működése

-> memóriát futtat
-> mi van ha hiba miatt adatra ugrik a futtatás?

ált crash
de
nem feltétlen

pl
credit warp -> 6:06

https://www.youtube.com/watch?v=14wqBA5Q1yc

4:50

https://www.youtube.com/watch?v=hB6eY73sLV0

remote code execution

boot

a processzor elindul x memóriacimtől,. és elkezd instruckiókat feldolgozni

Basic Input/Output System

 The BIOS in modern PCs initializes and tests the system hardware components, and loads a boot loader from a mass memory 
 device which then initializes an operating system. In the era of DOS, the BIOS provided a BIOS interrupt calls for the keyboard, 
 display, and other input/output devices that standardized an interface to application programs and the operating system.