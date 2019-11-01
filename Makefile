src := $(wildcard *.cpp)
obj := $(src:%.cpp=%.o)
hdr := $(wildcard *.hpp)
bin := gameOfLife

#CXX := $(shell which clang++ || which g++)
CXX := $(shell which g++ || which clang++)
CXXFLAGS := -Wall -W -std=c++11 -g3 -O0
LDFLAGS := -lncurses

UNAME := $(shell uname)
ifeq ($(UNAME),Linux)
  LDFLAGS := $(LDFLAGS) -lpthread
endif

all: $(bin)

$(bin): $(obj) $(hdr)
	$(CXX) -o $(bin) $(obj) $(LDFLAGS)

%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $(<) -o $(@)

.PHONY: clean
clean:
	rm -f $(bin) $(obj)
