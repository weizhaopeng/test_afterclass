(obj)=guess_number.o guess_number_game.o guess_number_record.o\
guess_number_rule.o

guess_number:$(obj)
	gcc -o guess_number $(obj)
guess_number.o:guess_number.c guess_number.h guess_number_rule.c\
guess_number_game.c

guess_number_game.o:guess_number_game.c guess_number.h \
guess_number_record.c

guess_number_record.o:guess_number_record.c guess_number.h

guess_number_rule.o:guess_number_rule.c guess_number.h

.PHONY:clean
clean:
	rm $(obj)

