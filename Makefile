OBJS := main.o Monster.o Hero.o JSON.o
CFLAGS := -Wall -Wextra -std=c++17
CC := g++-9
ALL := *.cpp
EXE := a.out
SCRIPT := test.sh

UNITS_DIR := units
TESTS_DIR := test

DOX := doxconf

VAL_OUT := leaklogfile.txt
CPPC_OUT := cppcheckfile.txt

a.out: $(OBJS)
	$(CC) $(CFLAGS) -o a.out $(OBJS)

main.o: main.cpp
	$(CC) $(CFLAGS) -c main.cpp

Monster.o: Monster.cpp 
	$(CC) $(CFLAGS) -c Monster.cpp

Hero.o: Hero.cpp
	$(CC) $(CFLAGS) -c Hero.cpp 

JSON.o: JSON.cpp
	$(CC) $(CFLAGS) -c JSON.cpp

clean:
	rm -rf *.o $(EXE) $(CPPC_OUT) $(VAL_OUT)

documentation:
	doxygen $(DOX)
	@echo "Documentation: DONE"

valgrind: $(EXE)
	valgrind --track-origins=yes --leak-check=full --log-file=$(VAL_OUT) --error-exitcode=1 ./$(EXE) $(UNITS_DIR)/Eivar.json $(UNITS_DIR)/Sigurd.json
	@echo "Valgrind: DONE"

cppcheck: 
	cppcheck --error-exitcode=1 $(ALL) --enable=warning
	cppcheck --output-file=$(CPPC_OUT) $(ALL) --enable=style,performance
	@echo "Cppcheck: DONE"

unit_test: 
	cd $(TESTS_DIR) && \
	cmake CMakeLists.txt && \
	make && \
	./runTests
	@echo "Unit test: DONE"

diff_test: $(EXE)
	./$(SCRIPT)
	diff results.txt expected_output.txt
	@echo "Diff test: DONE"