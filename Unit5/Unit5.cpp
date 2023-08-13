#include <iostream>
#include <string>
#include <vector>

class Guest {
public:
    std::string name;
    int roomNumber;

    Guest(const std::string& n, int room) : name(n), roomNumber(room) {}
};

class Hotel {
private:
    std::vector<Guest> guests;

public:
    void checkIn() {
        std::string name;
        int roomNumber;

        std::cout << "Enter guest name: ";
        std::cin >> name;

        std::cout << "Enter room number: ";
        std::cin >> roomNumber;

        guests.push_back(Guest(name, roomNumber));
        std::cout << "Guest checked in successfully.\n";
    }

    void checkOut() {
        int roomNumber;

        std::cout << "Enter room number: ";
        std::cin >> roomNumber;

        bool found = false;
        for (auto it = guests.begin(); it != guests.end(); ++it) {
            if (it->roomNumber == roomNumber) {
                guests.erase(it);
                std::cout << "Guest checked out successfully.\n";
                found = true;
                break;
            }
        }

        if (!found) {
            std::cout << "Room not found or guest not checked in.\n";
        }
    }

    void displayMenu() {
        std::cout << "\nHotel Management System\n";
        std::cout << "1. Check-In\n";
        std::cout << "2. Check-Out\n";
        std::cout << "3. Exit\n";
    }

    void run() {
        int choice;
        while (true) {
            displayMenu();
            std::cout << "Enter your choice: ";
            std::cin >> choice;

            switch (choice) {
                case 1:
                    checkIn();
                    break;
                case 2:
                    checkOut();
                    break;
                case 3:
                    std::cout << "Exiting the program.\n";
                    return;
                default:
                    std::cout << "Invalid choice. Please try again.\n";
            }
        }
    }
};

int main() {
    Hotel hotel;
    hotel.run();

    return 0;
}
