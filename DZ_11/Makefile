
all: Task1/main Task2/main Task3/main
	cd Task1 && ./main
	cd Task2 && ./main
	cd Task3 && ./main

Task1/main: Task1/DZ_11_1.c
	cd Task1 && gcc DZ_11_1.c -o main -pthread

Task2/main: Task2/DZ_11_2.c
	cd Task2 && gcc DZ_11_2.c -o main -pthread

Task3/main: Task3/DZ_11_3.c
		cd Task3 && gcc DZ_11_3.c -o main -pthread
