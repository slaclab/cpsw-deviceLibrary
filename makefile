OBJS=AxiMicronN25Q.o McsFileReader.o PromApiImpl.o MicronN25Q.o ../generic/McsRead.o

libprom.a: $(OBJS)
	ar cr $@ $^
	ranlib $@


%.o: %.cpp
	g++ -I. -I../generic -I./cpsw -O2 -c -o $@ $<

-include deps

deps: $(OBJS:%.o=%.cpp)
	$(CXX) $(CXXFLAGS) -I../generic -MM $^ > $@


clean:
	$(RM) *.o
	$(RM) libprom.a
