obj=insert_main.o insert_element.o bubble_sort.o 
insert:insert_element.o insert_main.o bubble_sort.o
	gcc -o insert $(obj)

insert_main.o:insert_element.c insert_element.h 

insert_element.o:insert_element.c bubble_sort.c insert_element.h

insert_bubble.o:bubble_sort.c insert_element.h

.PHONY:clean
clean:
	rm $(obj)


