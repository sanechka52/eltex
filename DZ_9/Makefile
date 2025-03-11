all: DZ_9_1 DZ_9_2
DZ_9_1: DZ_9_1.c
		gcc DZ_9_1.c -o DZ_9_1
		./DZ_9_1
DZ_9_2: DZ_9_2.c heder_9_2.h system_start.c opendirper.c draw_menu.c
		gcc DZ_9_2.c -o DZ_9_2 system_start.c opendirper.c draw_menu.c -L. -lncurses
		./DZ_9_2