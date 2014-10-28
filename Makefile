Driver.out: Hello.c
        gcc -Wall -ansi Hello.c -o Driver.out 

clean:
        rm -rf *.o
        rm -f *.out
        rm -f *~ *.h.gch *#[



