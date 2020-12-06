OBJS := main.o Monster.o Hero.o JSON.o
CFLAGS := -Wall -Wextra -std=c++17
CC := g++ 
DOX := doxconf
UNITS_DIR := units
TESTS_DIR := test
EXE := a.out
SCRIPT := test.sh

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
	rm -rf *.o $(EXE) cppcheckfile.txt leaklogfile.txt

documentation:
	doxygen $(DOX)
	@echo "Documentation: DONE"

valgrind:
	valgrind --track-origins=yes --leak-check=full --log-file=leaklogfile.txt --error-exitcode=1 ./$(EXE) $(UNITS_DIR)/Eivar.json $(UNITS_DIR)/Sigurd.json

cppcheck:
	cppcheck --error-exitcode=1 *.cpp --enable=warning
	cppcheck --output-file=cppcheckfile.txt *.cpp --enable=style,performance
	@echo "Cppcheck: DONE"

unit_test:
	cd $(TESTS_DIR) && \
	sudo cmake CMakeLists.txt && \
	sudo make && \
	./runTests
	@echo "Unit test: DONE"

diff_test:
	./$(SCRIPT)
	diff results.txt expected_output.txt
	@echo "Diff test: DONE"