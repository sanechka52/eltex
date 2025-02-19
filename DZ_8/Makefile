export LD_LIBRARY_PATH := $(CURDIR):$(LD_LIBRARY_PATH)

test: DZ_8.c vvod.c antivvod.c add.c sub.c mul.c div.c
		gcc div.c add.c mul.c sub.c -fPIC -c
		gcc -shared div.o add.o mul.o sub.o -o libmyname.so
		gcc DZ_8.c antivvod.c vvod.c -o test -L. -lmyname
		./test
