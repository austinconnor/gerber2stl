gerber2stl: main.o os.o parser.o math_utils.o converter.o gerber.o
	g++ main.o os.o parser.o math_utils.o converter.o gerber.o -o gerber2stl -std=c++17 -g

main.o: main.cc
	g++ -c main.cc -g -std=c++17

os.o: os.cc
	g++ -c os.cc -g -std=c++17

parser.o: parser.cc
	g++ -c parser.cc -g -std=c++17

math_utils.o: math_utils.cc
	g++ -c math_utils.cc -g -std=c++17

converter.o: converter.cc
	g++ -c converter.cc -g -std=c++17

gerber.o: gerber.cc
	g++ -c gerber.cc -g -std=c++17

clean:
	rm *.o gerber2stl

test:
	mkdir ./test_files/out/ && ./gerber2stl ./test_files/test/ ./test_files/out/