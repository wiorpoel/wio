

exec 		:= 	bin/wio
object		:=	object/token.o \
				object/io.o \
				object/chunk.o \
				object/memory.o


all: $(exec) 

$(exec): setup src/main.c $(object)
	gcc -Werror -Wall -Wextra -o $(exec) src/main.c $(object)


setup:
	@mkdir -p bin object

# TOKEN

object/token.o: src/token.c include/token.h
	gcc -Werror -Wall -Wextra -o object/token.o -c src/token.c


# IO

object/io.o: src/io.c include/io.h
	gcc -Werror -Wall -Wextra -o object/io.o -c src/io.c


# CHUNK

object/chunk.o: src/chunk.c include/chunk.h
	gcc -Werror -Wall -Wextra -o object/chunk.o -c src/chunk.c


# MEMORY

object/memory.o: src/memory.c include/memory.h
	gcc -Werror -Wall -Wextra -o object/memory.o -c src/memory.c