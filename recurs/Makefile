#生成target可执行文件
target:recurs.o
	gcc -g -o target recurs.o
#list.o practice.o是生成目标的先决条件
recurs.o:recurs.cpp recurs.h
	gcc -g -c recurs.cpp
#清除已经生成的目标
clean:
	rm -rf target *.o *.core