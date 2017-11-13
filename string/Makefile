obj=insert_main.o insert_element.o bubble_sort.o 
insert:insert_element.o insert_main.o bubble_sort.o
	gcc -o insert $(obj)
insert_element.o:insert_element.c insert_element.h

bubble_sort.o:bubble_sort.c insert_element.h

insert_main.o:insert_main.c insert_element.h

.PHONY:clean
	rm $(obj)

