all:	whereKey overflowKey
	
whereKey:	where_key.c
	gcc -g -m32 -o whereKey where_key.c

overflowKey:	overflowKey.c
	gcc -g -o overflowKey overflowKey.c

run:	whereKey overflowKey
	@./overflowKey | ./whereKey

clean:
	@rm whereKey && rm overflowKey