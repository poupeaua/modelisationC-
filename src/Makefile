PROG = Matrice
OBJS = Matrice.o
CXX = g++
CXXFLAGS = -Wall -g -O3 -march=native

$(PROG): $(OBJS)
		$(CXX) $(CXXFLAGS) -o $@ $(OBJS)

%.o:%.cxx
		$(CXX) -c $(CXXFLAGS) -o $@ $<
