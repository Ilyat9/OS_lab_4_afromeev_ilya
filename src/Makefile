CC = gcc
CFLAGS = -Wall -fPIC

all: lib1.so lib2.so prog1 prog2

# Сборка динамических библиотек
lib1.so: lib1.o
 $(CC) -shared -o lib1.so lib1.o -lm

lib2.so: lib2.o
 $(CC) -shared -o lib2.so lib2.o

lib1.o: lib1.c contracts.h
 $(CC) $(CFLAGS) -c lib1.c

lib2.o: lib2.c contracts.h
 $(CC) $(CFLAGS) -c lib2.c

# Сборка Программы 1 (линковка с lib1 по умолчанию)
# -L. указывает искать библиотеки в текущей папке
# -Wl,-rpath,. записывает путь к библиотеке в сам исполняемый файл (чтобы не настраивать LD_LIBRARY_PATH)
prog1: prog1.o lib1.so
 $(CC) -o prog1 prog1.o -L. -l1 -Wl,-rpath,. -lm

prog1.o: prog1.c contracts.h
 $(CC) $(CFLAGS) -c prog1.c

# Сборка Программы 2 (использует dlfcn)
prog2: prog2.o
 $(CC) -o prog2 prog2.o -ldl

prog2.o: prog2.c
 $(CC) $(CFLAGS) -c prog2.c

clean:
 rm -f *.o *.so prog1 prog2
