install:
	curl -o /tmp/ncurses.tar.gz "https://ftp.gnu.org/pub/gnu/ncurses/ncurses-6.4.tar.gz"
	tar -xvzf /tmp/ncurses.tar.gz -C /tmp/
	cd /tmp/ncurses-6.4 && ./configure && make -j 8
compile:
	gcc main.c -lncurses -o main.out
run:
	make compile
	./main.out
