CXX = g++
CXXFLAGS = -std=c++11 -I/path/to/mysql-connector/include
LDFLAGS = -L/path/to/mysql-connector/lib -lmysqlcppconn

SRC = src/main.cpp src/database.cpp src/sports.cpp src/field.cpp src/venue.cpp src/booking.cpp src/customer.cpp src/schedule.cpp src/extras.cpp
OBJ = $(SRC:.cpp=.o)

all: sports_booking_system

sports_booking_system: $(OBJ)
    $(CXX) $(CXXFLAGS) -o $@ $^ $(LDFLAGS)

clean:
    rm -f $(OBJ) sports_booking_system
