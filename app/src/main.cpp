#include "main.h"

int main() {

    std::shared_ptr<Data> data = std::make_shared<Data>(
        getFirstLineFromFile("token.tkn"));

    TgBot::Bot botClient(data->Token());
    
    botClient.getEvents().onCommand("start", [&botClient](TgBot::Message::Ptr message) {
        botClient.getApi().sendMessage(message->chat->id, "hi!");
    });
    
    botClient.getEvents().onCommand("quit", [&botClient, &data](TgBot::Message::Ptr message) {
        data->SetRun(false);
        botClient.getApi().sendMessage(message->chat->id, "quiting");
    });
    
    botClient.getEvents().onAnyMessage([&botClient](TgBot::Message::Ptr message) {
        std::cout << "user wrote: " << message->text << "\n";
        if (StringTools::startsWith(message->text, "/start"))
        {
            return;
        }
        if (StringTools::startsWith(message->text, "/quit"))
        {
            return;
        }
        botClient.getApi().sendMessage(message->chat->id, "your message is: " + message->text);
    });
    
    try
    {
        std::cout << "bot username: " << botClient.getApi().getMe()->username << "\n";
        TgBot::TgLongPoll longPoll(botClient);
        while (data->Run())
        {
            std::cout << "long poll started\n";
            longPoll.start();
        }
    }
    catch (const std::exception& e)
    {
        std::cout << "Error: " << e.what() << "\n";
    }

    return 0;
}

