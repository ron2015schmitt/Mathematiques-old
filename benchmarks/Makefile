
EXEC = vectorbenchmark benchmark

include ../Makefile


vectorbenchmark.o: vectorbenchmark.cpp $(DITZ)
	$(CXX) $(CXXFLAGS) -D 'COMPILEOPTS="'"$(CXXOPTFLAGS)"'"' -D 'VERS="'"$(FNAME)"'"' -c $< -o $@

benchmark.o: benchmark.cpp $(DITZ)
	$(CXX) $(CXXFLAGS)  -D 'COMPILEOPTS="'"$(CXXOPTFLAGS)"'"' -D 'VERS="'"$(FNAME)"'"' -c $< -o $@

results: $(EXEC)
	vectorbenchmark > vectorbenchmark.$(FNAME).results
	benchmark > benchmark.$(FNAME).results


#	$(CXX) $(CXXFLAGS) -D 'COMPILEOPTS="'"$(CXXOPTFLAGS)"'"' -c $< -S


