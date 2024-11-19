#include <iostream>
#include <vector>
#include <string>
using namespace std;

// Passenger class
class Passenger {
private:
    string name;
    int age;
    string ticketNumber;

public:
    // Constructor
    Passenger(string name, int age, string ticketNumber)
        : name(name), age(age), ticketNumber(ticketNumber) {}

    string getTicketNumber() const {
        return ticketNumber;
    }

    
    void display() const {
        cout << "Name: " << name << ", Age: " << age 
             << ", Ticket Number: " << ticketNumber << endl;
    }
};

class TicketReservationSystem {
private:
    vector<Passenger*> passengers; 
public:
    ~TicketReservationSystem() {
      
        for (Passenger* passenger : passengers) {
            delete passenger;
        }
    }


    void addPassenger(string name, int age, string ticketNumber) {
        Passenger* newPassenger = new Passenger(name, age, ticketNumber);
        passengers.push_back(newPassenger);
    }

    void displayAllPassengers() const {
        if (passengers.empty()) {
            cout << "No passengers in the system.\n";
            return;
        }
        for (const Passenger* passenger : passengers) {
            passenger->display();
        }
    }

    
    void searchByTicketNumber(string ticketNumber) const {
        for (const Passenger* passenger : passengers) {
            if (passenger->getTicketNumber() == ticketNumber) {
                cout << "Passenger found:\n";
                passenger->display();
                return;
            }
        }
        cout << "Passenger with ticket number " << ticketNumber << " not found.\n";
    }
};


int main() {
    TicketReservationSystem system;

  
    system.addPassenger("Alice", 30, "A123");
    system.addPassenger("Bob", 25, "B456");
    system.addPassenger("Charlie", 35, "C789");

    cout << "All Passengers:\n";
    system.displayAllPassengers();

    cout << "\nSearching for ticket number B456:\n";
    system.searchByTicketNumber("B456");

    cout << "\nSearching for ticket number D000:\n";
    system.searchByTicketNumber("D000");

    return 0;
}



Ans1:Storing objects as pointers allows for dynamic memory allocation, giving us the flexibility to manage memory usage efficiently. It also helps avoid issues with slicing when working with derived classes in inheritance scenarios

Ans2:The function iterates over the array of Passenger pointers, checking if the ticket number of each passenger matches the input. If a match is found, it displays the passenger details and exits. If no match is found, it displays a "not found" message.

Ans3: Without pointers, we would store the objects directly in the collection, which might lead to:
Increased memory usage due to copying large objects.
Difficulty managing objects with polymorphism (e.g., derived classes).
Issues with freeing dynamically allocated memory.
