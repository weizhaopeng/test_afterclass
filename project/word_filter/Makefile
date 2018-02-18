obj = word_filter.o stream_parse_file_impl.o data_store_list_impl.o

word_filter : $(obj)
	gcc -o $(obj)

word_filter.o : word_filter.c stream_parse_file_impl.c\
				data_store_list_impl.c

stream_parse_file_impl.o :  stream_parse_file_impl.c 

data_store_list_impl.o   : data_store_list_impl.c 

.PHONY:
clean:
	rm $(obj)

