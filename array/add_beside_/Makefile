obj=add_beside_main.o add_beside_faction.o

add_beside:$(obj)
	gcc $(obj) -o add_beside

add_beside_main.o:add_beside_main.c add_beside.h
	gcc -c add_beside_main.c
add_beside_faction.o:add_beside_faction.c add_beside.h
	gcc -c add_beside_faction.c

.PHONY:clean
clean:
	-rm $(obj)
