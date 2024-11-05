#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <map>
#include <limits>

using namespace std;

class Booking {
public:
    string game;
    string user_name;

    Booking(string game, string user_name)
        : game(game), user_name(user_name) {}

    string toString() const {
        return game + "," + user_name;
    }
};

class User {
public:
    string name;
    string phone_number;

    User(string name, string phone_number)
        : name(name), phone_number(phone_number) {}

    string toString() const {
        return name + "," + phone_number;
    }
};

class SportsBookingSystem {
private:
    vector<User> users;
    vector<Booking> bookings;
    vector<string> availableGames = {
        "Football Match: Real Madrid vs Barcelona, 2024-12-01, 15:00",
        "Football Match: Manchester United vs Liverpool, 2024-12-02, 18:00",
        "Football Match: Bayern Munich vs Paris Saint-Germain, 2024-12-03, 20:00",
        "Football Match: Juventus vs AC Milan, 2024-12-04, 17:00",
        "Tennis Match: Rafael Nadal vs Novak Djokovic, 2024-12-05, 13:00",
        "Tennis Match: Serena Williams vs Naomi Osaka, 2024-12-06, 11:00",
        "Tennis Match: Roger Federer vs Andy Murray, 2024-12-07, 14:00",
        "Basketball Match: Los Angeles Lakers vs Golden State Warriors, 2024-12-08, 19:00",
        "Basketball Match: Boston Celtics vs Miami Heat, 2024-12-09, 18:00"
    };
    map<string, map<string, double>> userBets; // This will track each user's bets on each team
    vector<string> extras = { "T-Shirt ($20)", "Cap ($15)", "Popcorn ($5)", "Drink ($3)" };
    vector<double> extraPrices = { 20.0, 15.0, 5.0, 3.0 };
    User* currentUser = nullptr;

    void loadData() {
        ifstream userFile("users.txt");
        string line;
        while (getline(userFile, line)) {
            size_t pos = line.find(',');
            string name = line.substr(0, pos);
            string phone_number = line.substr(pos + 1);
            users.push_back(User(name, phone_number));
        }
        userFile.close();

        ifstream bookingFile("bookings.txt");
        while (getline(bookingFile, line)) {
            size_t pos1 = line.find(',');
            string game = line.substr(0, pos1);
            string user_name = line.substr(pos1 + 1);
            bookings.push_back(Booking(game, user_name));
        }
        bookingFile.close();

        // Load user-specific betting data
        ifstream betFile("bets.txt");
        while (getline(betFile, line)) {
            size_t pos1 = line.find(',');
            size_t pos2 = line.find(',', pos1 + 1);
            string user_name = line.substr(0, pos1);
            string team = line.substr(pos1 + 1, pos2 - pos1 - 1);
            double amount = stod(line.substr(pos2 + 1));
            userBets[user_name][team] = amount;
        }
        betFile.close();
    }

    void saveData() {
        ofstream userFile("users.txt");
        for (const auto& user : users) {
            userFile << user.toString() << endl;
        }
        userFile.close();

        ofstream bookingFile("bookings.txt");
        for (const auto& booking : bookings) {
            bookingFile << booking.toString() << endl;
        }
        bookingFile.close();

        // Save user-specific betting data
        ofstream betFile("bets.txt");
        for (const auto& user_bet : userBets) {
            for (const auto& bet : user_bet.second) {
                betFile << user_bet.first << "," << bet.first << "," << bet.second << endl;
            }
        }
        betFile.close();
    }

public:
    SportsBookingSystem() {
        loadData();
    }

    ~SportsBookingSystem() {
        // Data is saved on logout now, no need to save here
    }

    void registerUser(const string& phone_number) {
        string name;
        cout << "Enter your name: ";
        cin.ignore();
        getline(cin, name);

        users.push_back(User(name, phone_number));
        cout << "Registration successful! Welcome, " << name << "!\n";
        currentUser = &users.back();
        cout << "You are now logged in as " << currentUser->name << ".\n";
    }

    bool loginUser(const string& phone_number) {
        for (auto& user : users) {
            if (user.phone_number == phone_number) {
                currentUser = &user;
                cout << "Login successful, welcome " << user.name << "!\n";
                return true;
            }
        }
        return false;
    }

    void showAvailableGames() {
        cout << "Available games and events:\n";
        for (int i = 0; i < availableGames.size(); i++) {
            cout << i + 1 << ". " << availableGames[i] << endl;
        }
    }

    void bookTickets() {
        if (!currentUser) {
            cout << "You need to log in first!\n";
            return;
        }

        showAvailableGames();
        int choice;
        cout << "Select a game by number: ";
        cin >> choice;

        if (choice < 1 || choice > availableGames.size()) {
            cout << "Invalid choice.\n";
            return;
        }

        string game = availableGames[choice - 1];
        bookings.push_back(Booking(game, currentUser->name));
        cout << "Booking successful for " << game << ".\n";
        saveData();
    }

    void showBookings() {
        if (!currentUser) {
            cout << "You need to log in first!\n";
            return;
        }

        cout << "Your bookings:\n";
        bool hasBookings = false;
        for (const auto& booking : bookings) {
            if (booking.user_name == currentUser->name) {
                cout << "Game: " << booking.game << endl;
                hasBookings = true;
            }
        }

        if (!hasBookings) {
            cout << "You have no bookings.\n";
        }
    }

    void betOnTeam() {
        if (!currentUser) {
            cout << "You need to log in first!\n";
            return;
        }

        showAvailableGames();
        int gameChoice;
        cout << "Select a game to bet on by number: ";
        cin >> gameChoice;

        if (gameChoice < 1 || gameChoice > availableGames.size()) {
            cout << "Invalid choice.\n";
            return;
        }

        string selectedGame = availableGames[gameChoice - 1];
        string team1, team2;
        if (selectedGame.find("vs") != string::npos) {
            size_t pos1 = selectedGame.find("vs");
            team1 = selectedGame.substr(selectedGame.find(":") + 2, pos1 - selectedGame.find(":") - 3);
            team2 = selectedGame.substr(pos1 + 3, selectedGame.find(",", pos1) - pos1 - 3);
        }

        cout << "Teams in this match: " << team1 << " vs " << team2 << endl;
        cout << "Select a team to bet on:\n";
        cout << "1. " << team1 << "\n";
        cout << "2. " << team2 << "\n";
        int teamChoice;
        cin >> teamChoice;

        if (teamChoice == 1 || teamChoice == 2) {
            double betAmount;
            cout << "Enter bet amount: $";
            cin >> betAmount;

            string selectedTeam = (teamChoice == 1) ? team1 : team2;
            userBets[currentUser->name][selectedTeam] += betAmount;
            cout << "You have successfully placed a bet of $" << betAmount << " on " << selectedTeam << "!\n";
            saveData();
        } else {
            cout << "Invalid choice. No bet placed.\n";
        }
    }

    void showBettingSummary() {
        if (!currentUser) {
            cout << "You need to log in first!\n";
            return;
        }

        cout << "Betting Summary for " << currentUser->name << ":\n";
        if (userBets[currentUser->name].empty()) {
            cout << "No bets placed.\n";
            return;
        }

        for (const auto& bet : userBets[currentUser->name]) {
            cout << bet.first << ": $" << bet.second << endl;
        }
    }

    void listGames() {
        showAvailableGames();
    }

    void buyExtras() {
        if (!currentUser) {
            cout << "You need to log in first!\n";
            return;
        }

        cout << "Extras available for purchase:\n";
        for (int i = 0; i < extras.size(); i++) {
            cout << i + 1 << ". " << extras[i] << endl;
        }

        cout << "Select an extra to buy (Enter 0 to exit): ";
        int choice;
        cin >> choice;

        if (choice == 0) {
            cout << "Exiting extras purchase.\n";
            return;
        }

        if (choice < 1 || choice > extras.size()) {
            cout << "Invalid choice.\n";
            return;
        }

        int quantity;
        cout << "Enter quantity for " << extras[choice - 1] << ": ";
        cin >> quantity;

        double totalPrice = extraPrices[choice - 1] * quantity;
        cout << "Total cost for " << quantity << " " << extras[choice - 1] << ": $" << totalPrice << endl;
        cout << "Purchase successful!\n";
    }

    void run() {
        while (true) {
            cout << "\n------ Sports Booking System ------\n";
            cout << "Enter your phone number (or type 0 to exit): ";
            string phone_number;
            cin >> phone_number;

            if (phone_number == "0") {
                cout << "Exiting system...\n";
                return;
            }

            if (loginUser(phone_number)) {
                mainMenu();
            } else {
                cout << "Phone number not found. Let's register you.\n";
                registerUser(phone_number);
                mainMenu();
            }
        }
    }

    void mainMenu() {
        while (true) {
            cout << "\n------ Main Menu ------\n";
            cout << "1. Book Tickets\n";
            cout << "2. Show Bookings\n";
            cout << "3. Bet on a Team\n";
            cout << "4. Show Betting Summary\n";
            cout << "5. List All Games\n";
            cout << "6. Buy Extras (Merchandise, Food, etc.)\n";
            cout << "7. Logout\n";
            cout << "Enter your choice: ";
            int choice;
            cin >> choice;

            switch (choice) {
                case 1: bookTickets(); break;
                case 2: showBookings(); break;
                case 3: betOnTeam(); break;
                case 4: showBettingSummary(); break;
                case 5: listGames(); break;
                case 6: buyExtras(); break;
                case 7: 
                    currentUser = nullptr; 
                    cout << "Logged out successfully.\n";
                    saveData();
                    return;
                default: cout << "Invalid choice, please try again.\n"; break;
            }
        }
    }
};

int main() {
    SportsBookingSystem system;
    system.run();
    return 0;
}
