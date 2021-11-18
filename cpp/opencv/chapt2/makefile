CC = g++
CXXFLAGS = -std=c++11
OPENCV = `pkg-config --cflags --libs opencv4`

%.exe: %.cpp
	$(CC) $(OPENCV) $(CXXFLAGS) $< -o $@

%.x: %.cpp
	$(CC) $(OPENCV) $(CXXFLAGS) $< -o $@

clean:
	rm -f *.exe *.o 
