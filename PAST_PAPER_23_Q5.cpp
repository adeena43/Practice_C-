#include <iostream>
#include <fstream>
#include <vector>
#include <sstream>
#include <algorithm>
using namespace std;

class Bot_Exception
{
    string message;

public:
    Bot_Exception(const string &msg) : message(msg) {}
    string what() const { return message; }
};

class User
{
    string username, country, interest;
    int age;

public:
    User(string username, string country, string interest, int age)
        : username(username), country(country), interest(interest), age(age) {}

    string get_username() const { return username; }
    string get_interest() const { return interest; }

    void Ask(string query);
};

class Chatbot
{
protected:
    int total_users = 0;
    string recent_user;

public:
    virtual string generate_response(string query, const User &u) = 0;
    virtual void increment_user_count() { ++total_users; }
    virtual int get_user_count() const { return total_users; }
};

class MedicalChatbot : public Chatbot
{
    int instance_count = 0;

public:
    MedicalChatbot() { ++instance_count; }
    string generate_response(string query, const User &u)
    {
        recent_user = u.get_username();
        increment_user_count();
        return "Medical response to " + query;
    }
    int get_instance_count() { return instance_count; }
};

class TechnologyChatbot : public Chatbot
{
    int instance_count = 0;

public:
    TechnologyChatbot() { ++instance_count; }
    string generate_response(string query, const User &u)
    {
        recent_user = u.get_username();
        increment_user_count();
        return "Technology response to " + query;
    }
    int get_instance_count() { return instance_count; }
};

class LegalChatbot : public Chatbot
{
    int instance_count = 0;

public:
    LegalChatbot() { ++instance_count; }
    string generate_response(string query, const User &u)
    {
        recent_user = u.get_username();
        increment_user_count();
        return "Legal response to " + query;
    }
    int get_instance_count() { return instance_count; }
};

class GeneralChatbot : public Chatbot
{
    int instance_count;

public:
    GeneralChatbot() { ++instance_count; }
    string generate_response(string query, const User &u)
    {
        recent_user = u.get_username();
        increment_user_count();
        return "General response to " + query;
    }
    int get_instance_count() { return instance_count; }
};

// User method implementation
void User::Ask(string query)
{
    try
    {
        if (query.find("doc") == 0)
        {
            MedicalChatbot med;
            cout << med.generate_response(query, *this) << endl;
        }
        else if (query.find("attorney") == 0)
        {
            LegalChatbot legal;
            cout << legal.generate_response(query, *this) << endl;
        }
        else if (query.find("guru") == 0)
        {
            TechnologyChatbot tech;
            cout << tech.generate_response(query, *this) << endl;
        }
        else if (query.find("special") == 0)
        {
            if (interest == "medical")
            {
                MedicalChatbot med;
                cout << med.generate_response(query, *this) << endl;
            }
            else if (interest == "legal")
            {
                LegalChatbot legal;
                cout << legal.generate_response(query, *this) << endl;
            }
            else if (interest == "technology")
            {
                TechnologyChatbot tech;
                cout << tech.generate_response(query, *this) << endl;
            }
            else
            {
                GeneralChatbot general;
                cout << general.generate_response(query, *this) << endl;
            }
        }
        else
        {
            throw Bot_Exception("Invalid query prefix");
        }
    }
    catch (Bot_Exception &e)
    {
        ofstream error_log("error_log.txt", ios::app);
        error_log << username << ": " << query << endl;
        error_log.close();
        cout << "Exception: " << e.what() << endl;
    }
}

void Analysis()
{
    ifstream read("error_log.txt");
    bool userFound = false;
    int cnt = 0;
    string username;
    int countexception[100];
    string name[100];
    string line;
    while (getline(read, line))
    {
        int spaceCounter = 0;
        for (int i = 0; i < line.length(); i++)
        {
            if (line[i] == ' ')
            {
                spaceCounter++;
            }
            else
            {
                if (spaceCounter == 0)
                {
                    username += line[i];
                }
            }
        }

        for (int i = 0; i < cnt; i++)
        {
            if (username == name[i])
            {
                countexception[i] = countexception[i] + 1;
                userFound = true;
                break;
            }
        }
        if (!userFound)
        {
            name[cnt] = username;
            countexception[cnt] = 1;
            cnt++;
        }
    }
    int max_queries = countexception[0];
    int maxUserIndex;
    for (int i = 1; i < cnt; i++)
    {
        if (countexception[i] > max_queries)
        {
            max_queries = countexception[i];
            maxUserIndex = i;
        }
    }
    cout << "Maximum Number Of Queries Held By: " << name[maxUserIndex] << endl;
    read.close();
}

int main()
{
    User u1("Alice", "USA", "medical", 25);
    User u2("Bob", "UK", "technology", 30);
    User u3("Charlie", "Canada", "legal", 35);

    u1.Ask("doc How are you?");
    u2.Ask("guru What's new?");
    u3.Ask("attorney Need legal advice");
    u1.Ask("unknown prefix query");

    Analysis();

    return 0;
}
