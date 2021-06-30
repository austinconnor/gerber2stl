gerber2stl: main.o os.o parser.o math_utils.o converter.o gerber.o
	g++ main.o os.o parser.o math_utils.o converter.o gerber.o -o gerber2stl -std=c++17 -lstdc++fs -g

main.o: main.cc
	g++ -c main.cc -g

os.o: os.cc
	g++ -c os.cc -g

parser.o: parser.cc
	g++ -c parser.cc -g

math_utils.o: math_utils.cc
	g++ -c math_utils.cc -g

converter.o: converter.cc
	g++ -c converter.cc -g

gerber.o: gerber.cc
	g++ -c gerber.cc -g

clean:
	rm *.o gerber2stl

test:
	./gerber2stl ./test_files/test/ ./test_files/out/