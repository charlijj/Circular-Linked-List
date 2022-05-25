
all: lab5x lab5g

lab5x: lab5.o circlist.o
	g++ -Wall -Wextra lab5.o circlist.o -o lab5x

lab5.o: lab5.cpp lab5.h circlist.h
	g++ -Wall -Wextra -c lab5.cpp -o lab5.o

circlist.o: circlist.cpp circlist.h
	g++ -Wall -Wextra -c circlist.cpp -o circlist.o

lab5g: lab5g.o circlistg.o
	g++ -g -Wall -Wextra lab5g.o circlistg.o -o lab5g

lab5g.o: lab5.cpp lab5.h circlist.h
	g++ -g -Wall -Wextra -c lab5.cpp -o lab5g.o

circlistg.o: circlist.cpp circlist.h
	g++ -g -Wall -Wextra -c circlist.cpp -o circlistg.o

.PHONY: clean
clean:
	rm -f circlist.o circlistg.o lab5.o lab5g.o lab5x lab5g

