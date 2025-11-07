progname=Vector
utest=utest_$(progname)
bench=bench_$(progname)
lib=lib$(progname).a
shared_lib=$(progname).so
CXX=g++
CXXFLAGS=-Wall -Wextra -Werror -std=c++11 -I. -I./templates -I./headers

debug:   CXXFLAGS+=-g3
release: CXXFLAGS+=-g0 -DNDEBUG

# Ներառել բոլոր .cpp ֆայլերը, ներառյալ templates-ը
SOURCES=$(wildcard sources/*.cpp) main.cpp
PREPROCS=$(patsubst %.cpp,%.ii,$(SOURCES))
DEPENDS=$(patsubst %.cpp,%.d,$(SOURCES))
ASSEMBLES=$(patsubst %.cpp,%.s,$(SOURCES))
OBJS=$(patsubst %.cpp,%.o,$(SOURCES))

LIB_SOURCES=$(wildcard sources/*.cpp)
LIB_PREPROCS=$(patsubst %.cpp,%.ii,$(LIB_SOURCES))
LIB_DEPENDS=$(patsubst %.cpp,%.d,$(LIB_SOURCES))
LIB_ASSEMBLES=$(patsubst %.cpp,%.s,$(LIB_SOURCES))
LIB_OBJS=$(patsubst %.cpp,%.o,$(LIB_SOURCES))

UTEST_SOURCES=$(wildcard sources/*.cpp) main_utest.cpp
UTEST_PREPROCS=$(patsubst %.cpp,%.ii,$(UTEST_SOURCES))
UTEST_DEPENDS=$(patsubst %.cpp,%.d,$(UTEST_SOURCES))
UTEST_ASSEMBLES=$(patsubst %.cpp,%.s,$(UTEST_SOURCES))
UTEST_OBJS=$(patsubst %.cpp,%.o,$(UTEST_SOURCES))

BENCH_SOURCES=$(wildcard sources/*.cpp) main_bench.cpp
BENCH_PREPROCS=$(patsubst %.cpp,%.ii,$(BENCH_SOURCES))
BENCH_DEPENDS=$(patsubst %.cpp,%.d,$(BENCH_SOURCES))
BENCH_ASSEMBLES=$(patsubst %.cpp,%.s,$(BENCH_SOURCES))
BENCH_OBJS=$(patsubst %.cpp,%.o,$(BENCH_SOURCES))

TEST_INPUTS=$(wildcard tests/test*.input)
TESTS=$(patsubst %.input,%,$(TEST_INPUTS))

debug:   bench
release: utest bench

qa: $(TESTS)

test%: $(progname)
	./$< < $@.input > $@.output 2>/dev/null || echo "Negative test..."
	diff $@.output $@.expected > /dev/null && echo "$@ PASSED" || echo "$@ FAILED"

utest: $(utest)
	./$<

bench: $(bench)
	./$<

$(utest): $(UTEST_OBJS) | .gitignore
	$(CXX) $(CXXFLAGS) $^ -lgtest -o $@

$(bench): $(BENCH_OBJS) | .gitignore
	$(CXX) $(CXXFLAGS) $^ -lbenchmark -o $@

$(lib): $(LIB_OBJS) | .gitignore
	ar -crv $@ $^

$(shared_lib): $(LIB_OBJS) | .gitignore
	$(CXX) $(CXXFLAGS) $^ --shared -o $@

$(progname): $(OBJS) | .gitignore
	$(CXX) $(CXXFLAGS) $^ -o $@

%.ii: %.cpp
	$(CXX) $(CXXFLAGS) -E $< -o $@
	$(CXX) $(CXXFLAGS) -MM $< -MT $@ > $(patsubst %.ii,%.d,$@)

%.s: %.ii
	$(CXX) $(CXXFLAGS) -S $< -o $@

%.o: %.s
	$(CXX) $(CXXFLAGS) -c $< -o $@

.gitignore:
	echo $(progname) > .gitignore
	echo $(utest)   >> .gitignore
	echo $(bench)   >> .gitignore
	echo $(lib)     >> .gitignore
	echo $(shared_lib) >> .gitignore

install:
	cp headers/*.hpp /usr/local/include 2>/dev/null || true
	cp $(lib) /usr/local/lib 2>/dev/null || echo "No static lib"
	cp $(shared_lib) /usr/local/lib 2>/dev/null || echo "No dynamic lib"

clean:
	rm -rf *.ii *.d *.s *.o $(progname) $(utest) $(bench) $(lib) $(shared_lib) .gitignore *.output
	rm -rf sources/*.ii sources/*.d sources/*.s sources/*.o
	rm -rf templates/*.ii templates/*.d templates/*.s templates/*.o

distclean: clean
	rm -rf $(DEPENDS) $(UTEST_DEPENDS) $(BENCH_DEPENDS)

.PRECIOUS:  $(PREPROCS) $(ASSEMBLES) $(UTEST_PREPROCS) $(UTEST_ASSEMBLES) $(BENCH_PREPROCS) $(BENCH_ASSEMBLES)
.SECONDARY: $(PREPROCS) $(ASSEMBLES) $(UTEST_PREPROCS) $(UTEST_ASSEMBLES) $(BENCH_PREPROCS) $(BENCH_ASSEMBLES)

sinclude $(DEPENDS) $(UTEST_DEPENDS) $(BENCH_DEPENDS)
