hw3: stream.o keygen.o crypt.o invkey.o histo.o solve.o hw3.c
	gcc -o hw3 -g hw3.c -I/home/scf-22/csci551b/openssl/include -L/home/scf-22/csci551b/openssl/lib -lcrypto

keygen.o: keygen.c stream.o
	gcc -g -c -Wall keygen.c -I/home/scf-22/csci551b/openssl/include

stream.o: stream.c
	gcc -g -c -Wall stream.c -I/home/scf-22/csci551b/openssl/include

crypt.o: crypt.c
	gcc -g -c -Wall crypt.c

invkey.o: invkey.c
	gcc -g -c -Wall invkey.c

histo.o: histo.c
	gcc -g -c -Wall histo.c

solve.o: solve.c
	gcc -g -c -Wall solve.c

clean:
	rm -f *.o hw3
