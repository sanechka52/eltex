test: DZ_7.c vvod.c antivvod.c add.c sub.c mul.c div.c
		gcc add.c sub.c mul.c div.c -c
		ar rc libmyname.a add.o sub.o mul.o div.o
		gcc vvod.c antivvod.c DZ_7.c -o testlib -L. -lmyname
		./testlib 