all: compile run

compile: ThreeVersionsOfQuickSort.cpp
	g++ ThreeVersionsOfQuickSort.cpp -o sorting

run: sorting
	./sorting input.txt output.txt

clean:
	rm sorting