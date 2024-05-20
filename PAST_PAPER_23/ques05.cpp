#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include <map>
#include <stdexcept>

using namespace std;

// Custom exception class for bot errors
class Bot_Exception : public exception {
private:
    string message;

public:
    Bot_Exception(const string& msg) : message(msg) {}

    // Override the what() function to provide error message
    const char* what() const noexcept override {
        return message.c_str();
    }
};

// User class to store user data
class User {
private:
    string username;
    string country;
    string interest;
    int age;

public:
    User(string uname, string cntry, string intrst, int ag) 
        : username(uname), country(cntry), interest(intrst), age(ag) {}

    // Method to ask query and generate response
    string Ask(const string& query) {
        string prefix = get_prefix(query);
        if (prefix == "doc" && interest == "medical") {
            return "Medical response for query: " + query;
        } else if (prefix == "attorney" && interest == "legal") {
            return "Legal response for query: " + query;
        } else if (prefix == "guru" && interest == "technology") {
            return "Technology response for query: " + query;
        } else if (prefix == "special") {
            return "Query forwarded to relevant chatbot based on interest.";
        } else {
            throw Bot_Exception("Invalid query: " + query);
        }
    }

    // Getter method for username
    string getUsername() const { return username; }

private:
    // Function to extract prefix from query
    string get_prefix(const string& query) {
        istringstream iss(query);
        string prefix;
        iss >> prefix;
        return prefix;
    }
};

// Base class for chatbot
class Chatbot {
protected:
    string last_user;
    static int total_users;

public:
    // Method to generate response
    virtual string generate_response(const string& query, User& user) = 0;

    // Method to get total user count
    static int getTotalUsers() { return total_users; }
};

int Chatbot::total_users = 0; // Initializing static member

// Medical chatbot class
class MedicalChatbot : public Chatbot {
public:
    string generate_response(const string& query, User& user) override {
        last_user = user.getUsername();
        total_users++;
        return user.Ask(query);
    }
};

// Legal chatbot class
class LegalChatbot : public Chatbot {
public:
    string generate_response(const string& query, User& user) override {
        last_user = user.getUsername();
        total_users++;
        return user.Ask(query);
    }
};

// Technology chatbot class
class TechnologyChatbot : public Chatbot {
public:
    string generate_response(const string& query, User& user) override {
        last_user = user.getUsername();
        total_users++;
        return user.Ask(query);
    }
};

// General chatbot class
class GeneralChatbot : public Chatbot {
public:
    string generate_response(const string& query, User& user) override {
        last_user = user.getUsername();
        total_users++;
        return user.Ask(query);
    }
};

// Function to handle exceptions and log errors
void handle_exception(const Bot_Exception& e, const User& user) {
    cout << "Error: " << e.what() << endl;
    // Log error to error_log.txt
    ofstream error_log("error_log.txt", ios::app);
    if (error_log.is_open()) {
        error_log << "User: " << user.getUsername() << ", Query: " << e.what() << endl;
        error_log.close();
    } else {
        cerr << "Error: Unable to open error log file." << endl;
    }
}

// Function to analyze error log
void Analysis() {
    ifstream error_log("error_log.txt");
    if (error_log.is_open()) {
        string line;
        map<string, int> user_exceptions;
        int total_words = 0;
        while (getline(error_log, line)) {
            istringstream iss(line);
            string username, query_word;
            iss >> username;
            user_exceptions[username]++;
            while (iss >> query_word) {
                total_words++;
            }
        }
        error_log.close();

        // Print username with maximum exceptions
        string max_user;
        int max_exceptions = 0;
        for (const auto& entry : user_exceptions) {
            if (entry.second > max_exceptions) {
                max_exceptions = entry.second;
                max_user = entry.first;
            }
        }
        cout << "Username with maximum exceptions: " << max_user << endl;

        // Print total count of words from each query stored
        cout << "Total count of words from each query stored: " << total_words << endl;
    } else {
        cerr << "Error: Unable to open error log file for analysis." << endl;
    }
}

int main() {
    // Creating users
    User user1("John", "USA", "medical", 30);
    User user2("Alice", "UK", "technology", 25);
    User user3("Bob", "Canada", "legal", 40);

    // Creating chatbots
    MedicalChatbot med_chatbot;
    TechnologyChatbot tech_chatbot;
    LegalChatbot legal_chatbot;

    try {
        // Testing queries
        cout << med_chatbot.generate_response("doc How to treat flu?", user1) << endl;
        cout << tech_chatbot.generate_response("guru How to code in C++?", user2) << endl;
        cout << legal_chatbot.generate_response("attorney Legal advice for business contracts.", user3) << endl;
        cout << med_chatbot.generate_response("special Medical advice for diabetes.", user1) << endl;
        cout << tech_chatbot.generate_response("special Technology news update.", user2) << endl;
        cout << legal_chatbot.generate_response("special Legal consultation for property issues.", user3) << endl;

        // Testing invalid queries
        cout << med_chatbot.generate_response("Invalid query", user1) << endl;
    } catch (const Bot_Exception& e) {
        // Handle exceptions
        handle_exception(e, user1);
    }

    // Analyze error log
    Analysis();

    return 0;
}
