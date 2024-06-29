all: compile run

compile: MergeInsertionSort.cpp
	g++ MergeInsertionSort.cpp -o sorting

run: sorting
	./sorting input.txt output.txt

clean:
	rm sorting