#pragma once
#include <iostream>
#include <string>
#include <vector>
#include "01_Movie.cpp"
#include "03_Screen.cpp"
using namespace std;

class ShowSeat;

class Show {
    private:
        int showId;
        string startTime;
        //Aggregation
        Movie* movie;
        Screen* screen;
        //Composition
        vector<ShowSeat*> showSeats;

    public:
        Show(int showId, string startTime, Movie* movie, Screen* screen);
        ~Show();

        void displaySeatLayout();
        ShowSeat* getShowSeat(string seatNum);

        Movie* getMovie() { 
            return this->movie; 
        }
        Screen* getScreen() { 
            return this->screen; 
        }
        string getStartTime() { 
            return this->startTime; 
        }
};