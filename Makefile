all: run clean

run: reverseNum
	./reverseNum

reverseNum: reverseNum.c

clean:
	rm -f ./reverseNum
