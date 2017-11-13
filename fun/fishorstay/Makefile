obj=fiost_main.o fiost_leap.o fiost_day.o isright.o
fiost:$(obj)
	gcc $(obj) -o fiost

fiost_main.o:fiost_main.c fiost_day.c fiost_leap.c isright.c fiost.h

fiost_leap.o:fiost_leap.c fiost.h

fiost_day.o:fiost_day.c fiost_leap.c fiost.h

isright.o:isright.c fiost.h

.PHONY:
clean:
	rm $(obj)

