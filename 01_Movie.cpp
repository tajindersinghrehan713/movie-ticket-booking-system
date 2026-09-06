#pragma once
#include <string>
using namespace std;

//encapsulation
class Movie {
    private:
        string title;
        string language;
        int durationMinutes;

    public:
        Movie(string title, string language, int durationMinutes) {
            this->title = title;
            this->language = language;
            this->durationMinutes = durationMinutes;
        }

        Movie(string title) {
            this->title = title;
            this->language = "English";
            this->durationMinutes = 120;
        }

        string getTitle() { 
            return this->title; 
        }
        string getLanguage() { 
            return this->language; 
        }
        int getDurationMinutes() { 
            return this->durationMinutes; 
        }
};