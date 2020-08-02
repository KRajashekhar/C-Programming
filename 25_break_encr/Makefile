encrypt:encrypt.c
	gcc -o encrypt -Wall -Werror -pedantic -std=gnu99 encrypt.c
tests.txt:
	./encrypt 7 sample_text.txt > tests.txt
breaker:breaker.c
	gcc -o breaker -Wall -Werror -pedantic -std=gnu99 breaker.c
ans.txt:
	./breaker tests.txt > ans.txt
