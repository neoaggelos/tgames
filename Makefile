all: turrets mastermind

turrets: turrets-make
	make -f turrets-make
	sudo make install -f turrets-make

mastermind: mastermind-make
	make -f mastermind-make
	sudo make install -f mastermind-make

clean:
	rm -rf obj/* bin/*
	rmdir obj bin

