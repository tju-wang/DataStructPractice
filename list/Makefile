#生成target可执行文件
target:list.o practice.o
	gcc -g -o target list.o practice.o
#list.o practice.o是生成目标的先决条件
list.o:list.c list.h
	gcc -g -c list.c
practice.o:practice.c practice.h
	gcc -g -c practice.c
#清除已经生成的目标
clean:
	rm -rf target *.o *.core