CC=/usr/bin/g++
THREAD_FLAGS=-pthread
SOURCE1=fork-join.cpp
SOURCE2=rendezvous.cpp
SOURCE3=barrier.cpp
TARGET1=fork-join
TARGET2=rendezvous
TARGET3=barrier

build: $(SOURCE1) $(SOURCE2) $(SOURCE3) 
	$(CC) -o $(TARGET1) $(SOURCE1) $(THREAD_FLAGS)
	$(CC) -o $(TARGET2) $(SOURCE2) $(THREAD_FLAGS)
	$(CC) -o $(TARGET3) $(SOURCE3) $(THREAD_FLAGS)

fork_: $(TARGET1) 
	./$^

rendezvous_: $(TARGET2)
	./$^

barrier_: $(TARGET3)
	./$^ $(NUM_OF_THREADS)

clean:
	rm -f $(TARGET1) $(TARGET2) $(TARGET3)
