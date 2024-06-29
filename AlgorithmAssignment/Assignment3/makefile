all: compile run

compile: FindingLCS.cpp
	g++ FindingLCS.cpp -o lcs

run: lcs
	./lcs input.txt output.txt

clean:
	rm lcs