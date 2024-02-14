#
# modern cpp tutorial
#
# created by changkun at changkun.de
# https://github.com/changkun/modern-cpp-tutorial
#
BIN=bin
# a=$(patsubst %.cpp, bin/%.out, $(wildcard *.cpp))
# $(info $(a))
test = $(shell if [ -d $(BIN) ]; then echo "exist"; else echo "noexist"; fi)
all: $(patsubst %.cpp, bin/_%, $(wildcard *.cpp))


bin/_%: %.cpp Makefile
	@clang++ $< -o $@ -std=c++2a -pedantic
# ifneq ($(wildcard $(BIN)), $(BIN))
# 	$(shell mkdir $(BIN))
# endif
ifeq ("$(test)", "noexist")
 	$(shell mkdir $(BIN))
endif
clean:
	rm bin/* *.bin

