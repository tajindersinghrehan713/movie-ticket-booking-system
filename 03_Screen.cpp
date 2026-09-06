#pragma once
#include <string>
#include <vector>
#include "02_Seat.cpp"
using namespace std;

class Screen {
    private:
        int screenId;
        string screenName;
        //Composition
        vector<Seat> seats;

    public:
        Screen(int screenId, string screenName) {
            this->screenId = screenId;
            this->screenName = screenName;
        }

        void addSeat(Seat seat) {
            this->seats.push_back(seat);
        }

        vector<Seat>& getSeats() { 
            return this->seats; 
        }
        string getScreenName() { 
            return this->screenName; 
        }
        int getScreenId() { 
            return this->screenId; 
        }
};