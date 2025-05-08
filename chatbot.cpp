#include <iostream>
#include <string>
using namespace std;

void chatbotResponse(const string& userInput) {
    if (userInput == "hi" || userInput == "hello") {
        cout << "Chatbot: Hello! How can I help you today?\n";
    } 
    else if (userInput == "price" || userInput == "cost") {
        cout << "Chatbot: Our products range from $10 to $100. Do you want more details?\n";
    } 
    else if (userInput == "available" || userInput == "availability") {
        cout << "Chatbot: Yes, all items are currently in stock.\n";
    }
    else if (userInput == "location" || userInput == "address") {
        cout << "Chatbot: We are located at 123 Market Street, New York.\n";
    }
    else if (userInput == "contact" || userInput == "phone") {
        cout << "Chatbot: You can contact us at +1-234-567-890.\n";
    }
    else if (userInput == "thanks" || userInput == "thank you") {
        cout << "Chatbot: You're welcome! Let me know if you need anything else.\n";
    }
    else if (userInput == "bye" || userInput == "exit") {
        cout << "Chatbot: Thank you for visiting. Have a great day!\n";
    } 
    else if (userInput == "help") {
        cout << "Chatbot: You can ask me about product prices, availability, location, or say 'bye' to end chat.\n";
    }
    else {
        cout << "Chatbot: I'm sorry, I di=dn't understand that. Type 'help' to see what you can ask.\n";
    }
}

int main() {
    string userInput;
    cout << "Welcome to Customer Support Chatbot!\n";
    cout << "Type 'help' to see available options.\n";

    while (true) {
        cout << "\nYou: ";
        getline(cin, userInput);

        for (auto& c : userInput) c = tolower(c);

        if (userInput == "bye" || userInput == "exit") {
            chatbotResponse(userInput);
            break;
        }

        chatbotResponse(userInput);
    }

    return 0;
}
