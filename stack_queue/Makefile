#生成target可执行文件
target:stack.o
	gcc -g -o target stack.o
#list.o practice.o是生成目标的先决条件
stack.o:stack.c stack.h
	gcc -g -c stack.c
#清除已经生成的目标
clean:
	rm -rf target *.o *.core
