PROG = Dvector
OBJS = Dvector.o
CXX = g++
CXXFLAGS = -Wall -g

$(PROG): $(OBJS)
	$(CXX) $(CXXFLAGS) -o $@ $(OBJS)

%.o : %.cxx
	$(CXX) -c $(CXXFLAGS) -o $@ $<
