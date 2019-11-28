#生成target可执行文件
test:bin_tree.o test.o 
	gcc -g -o test bin_tree.o test.o
#list.o practice.o是生成目标的先决条件
bin_tree.o:bin_tree.c bin_tree.h
	gcc -g -c bin_tree.c
test.o:test.c test.h
	gcc -g -c test.c
#清除已经生成的目标
clean:
	rm -rf test *.o *.core
