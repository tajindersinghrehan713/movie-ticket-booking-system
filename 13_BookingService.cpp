#pragma once
#include <iostream>
#include <vector>
#include "04_Cinema.cpp"
#include "05_Show.cpp"
#include "06_ShowSeat.cpp"
#include "07_Customer.cpp"
#include "08_Booking.cpp"
#include "09_Payment.cpp"
#include "11_PriceCalculator.cpp"
#include "12_TicketPrinter.cpp"
#include "14_Snack.cpp"
using namespace std;

class BookingService {
    private:
        Cinema* cinema;
        vector<Show*> shows;
        vector<Booking*> bookings;
        vector<Snack> snacksCatalog;

    public:
        BookingService(Cinema* cinema) {
            this->cinema = cinema;
            this->snacksCatalog.push_back(Snack(1, "Popcorn", 200.0));
            this->snacksCatalog.push_back(Snack(2, "Coke", 80.0));
        }

        ~BookingService() {
            for (Booking* b : this->bookings) {
                delete b;
            }
            this->bookings.clear();
        }

        void addShow(Show* show) {
            this->shows.push_back(show);
        }

        Snack* getSnack(int id) {
            for (auto& s : this->snacksCatalog) {
                if (s.getSnackId() == id) return &s;
            }
            return nullptr;
        }

        // Default call: 4 parameters (Empty snacks vector passed by value)
        Booking* bookSeat(int showIndex, Customer* customer, string seatNum, Payment* paymentMethod) {
            vector<SnackOrder> emptySnacks;
            return this->bookSeat(showIndex, customer, seatNum, paymentMethod, emptySnacks);
        }

        Booking* bookSeat(int showIndex, Customer* customer, string seatNum, Payment* paymentMethod, vector<SnackOrder> snacks) {
            if (showIndex < 0 || showIndex >= static_cast<int>(this->shows.size())) {
                cout << "Invalid show selection.\n";
                return nullptr;
            }

            Show* selectedShow = this->shows[showIndex];
            ShowSeat* targetSeat = selectedShow->getShowSeat(seatNum);

            //Invalid seat number
            if (targetSeat == nullptr) {
                cout << "Seat \"" << seatNum << "\" does not exist in this auditorium!\n";
                return nullptr;
            }

            //booking a seat that is already BOOKED
            if (!targetSeat->isAvailable()) {
                cout << "Seat " << seatNum << " is already BOOKED. No changes made.\n";
                return nullptr;
            }

            vector<ShowSeat*> requestedSeats = { targetSeat };
            double amount = PriceCalculator::calculateTotal(requestedSeats, snacks);

            //failed payment
            if (!paymentMethod->pay(amount)) {
                cout << "Transaction could not be completed. Seat " 
                     << seatNum << " remains AVAILABLE.\n";
                return nullptr;
            }

            targetSeat->book();

            Booking* newBooking = new Booking(selectedShow, customer);
            newBooking->addSeat(targetSeat);
            for (auto& so : snacks) {
                newBooking->addSnackOrder(so);
            }
            newBooking->setBookingAmount(amount);
            newBooking->confirm();

            this->bookings.push_back(newBooking);
            TicketPrinter::printTicket(newBooking);

            return newBooking;
        }

        //cancellation
        bool cancelBooking(string bookingId) {
            for (auto* b : this->bookings) {
                if (b->getBookingId() == bookingId) {
                    if (b->getStatus() == BookingStatus::CANCELLED) {
                        cout << "Booking " << bookingId << " is already cancelled.\n";
                        return false;
                    }
                    b->cancel();
                    for (auto* seat : b->getBookedSeats()) {
                        seat->release();
                    }
                    cout << "Booking " << bookingId 
                         << " cancelled. Associated seats are now AVAILABLE again.\n";
                    return true;
                }
            }
            cout << "Booking ID " << bookingId << " not found!\n";
            return false;
        }
};