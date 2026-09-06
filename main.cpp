#include <iostream>
#include "01_Movie.cpp"
#include "02_Seat.cpp"
#include "03_Screen.cpp"
#include "04_Cinema.cpp"
#include "05_Show.cpp"
#include "06_ShowSeat.cpp"
#include "07_Customer.cpp"
#include "08_Booking.cpp"
#include "09_Payment.cpp"
#include "10_PaymentTypes.cpp"
#include "11_PriceCalculator.cpp"
#include "12_TicketPrinter.cpp"
#include "13_BookingService.cpp"
#include "14_Snack.cpp"
using namespace std;

int main() {
    Cinema cinema("PVR Pacific Mall");
    Screen audi1(1, "Audi-01 (IMAX)");
    audi1.addSeat(Seat("A1", SeatTier::PLATINUM));
    audi1.addSeat(Seat("A2", SeatTier::PLATINUM));
    audi1.addSeat(Seat("B1", SeatTier::GOLD));
    cinema.addScreen(audi1);

    // 2. Setup Catalog and Show
    Movie movie("Spider-Man: Brand New Day", "English", 150);
    Show eveningShow(101, "07:00 PM", &movie, &cinema.getScreens()[0]);

    BookingService service(&cinema);
    service.addShow(&eveningShow);

    Customer customer("Tajinder Singh", "+91-1234567890");

    cout << "\n======================================================\n";
    cout << "           MOVIE TICKET BOOKING SYSTEM                      \n";
    cout << "======================================================\n";

    eveningShow.displaySeatLayout();

    // Book 1 seat (A1) via UPI
    cout << "\n>>> Booking seat A1 via UPI...\n";
    UpiPayment upiSuccess("tajinder@okaxis", true);
    Booking* b1 = service.bookSeat(0, &customer, "A1", &upiSuccess);

    // Seat already BOOKED
    cout << "\n>>> Attempting to book already BOOKED seat A1...\n";
    UpiPayment upiRetry("other@upi", true);
    service.bookSeat(0, &customer, "A1", &upiRetry);

    //payment fails
    cout << "\n>>> Attempting to book seat A2 with failing payment...\n";
    UpiPayment upiFailing("tajinder@badupi", false);
    service.bookSeat(0, &customer, "A2", &upiFailing);
    eveningShow.displaySeatLayout();

    //cancellation
    if (b1 != nullptr) {
        cout << "\n>>> Cancelling booking " << b1->getBookingId() << "...\n";
        service.cancelBooking(b1->getBookingId());
        eveningShow.displaySeatLayout();
    }

    // invalid inputs handled cleanly
    cout << "\n>>>Selecting non-existent seat A21...\n";
    service.bookSeat(0, &customer, "A21", &upiSuccess);

    cout << "\n>>> Selecting invalid show index 5...\n";
    service.bookSeat(5, &customer, "A1", &upiSuccess);
    return 0;
}