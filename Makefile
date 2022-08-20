.PHONY:  build run # every make run shold run the program

build:
	clear
	mkdir -p ./build
	CC=/usr/bin/clang CXX=/usr/bin/clang++ cmake -B ./build -G "Unix Makefiles" . 
	make -C ./build

clean:
	rm -rf ./build
	rm -rf ./run

run: build
	rm -rf ./run
	mkdir ./run
	cp ./build/tictactoe ./run/tictactoe
	cp ./test/* ./run
	#################################################
	#################### RUNNING ####################
	#################################################
	./run/tictactoe

clean-build: clean build # look subtasks

release:
	# not done yet #
