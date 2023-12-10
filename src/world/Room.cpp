#include "Room.h"
#include <iostream>
#include <fstream>
#include <sstream>

Room::Room(std::string zone_name, std::string room_name) {
    zone_name_ = zone_name;
    room_name_ = room_name;
    std::string folder = "../assets/map/zone_" + zone_name_ + "room_" + room_name_;
    std::ifstream roomFile(folder + "/room.txt");
    if (!roomFile.is_open()) {
        std::cerr << "Cannot open Room file" << std::endl;
        exit(EXIT_FAILURE);
    } else {
        std::string line;
        roomFile >> size_.x >> size_.y;

        getline(roomFile, line);
        if (!background_texture_->loadFromFile(folder + "/" + line)) {
            std::cerr << "Cannot load room_" + room_name_ + "'s background" << std::endl;
            exit(EXIT_FAILURE);
        }

        roomFile >> spawnpoint_.x >> spawnpoint_.y;

        roomFile.close();
    }

    std::ifstream entityFile(folder + "/entities.txt");
    if (!entityFile.is_open()) {
        std::cerr << "Cannot open Entity file" << std::endl;
        exit(EXIT_FAILURE);
    } else {
        std::string line;
        std::cout << "TODO : recovery and creation of the entities" << std::endl;

        //PLaceholder test before real implementation of entity classes
        unsigned int i = 0;
        std::string word;
        while (!entityFile.eof()) {
            entityFile >> word;
            std::cout << "Entity " << i << "'s id : " << stoi(word);
            entityFile >> word;
            std::cout << "Entity " << i << "'s name : " << word;
            entityFile >> word;
            std::cout << "Entity " << i << "'s x coord : " << stoi(word);
            entityFile >> word;
            std::cout << "Entity " << i << "'s y coord : " << stoi(word);
            entityFile >> word;
            std::cout << "Entity " << i << "'s texture name : " << word;
            i++;
        }
        entityFile.close();
    }

    std::ifstream triggerFile(folder + "/triggers.txt");
    if (!entityFile.is_open()) {
        std::cerr << "Cannot open Trigger file" << std::endl;
        exit(EXIT_FAILURE);
    } else {
        std::string line;
        std::string word;

        std::string name;
        sf::IntRect rect;
        TriggerType type;
        std::string action;
        std::vector<std::string> args;

        while (!triggerFile.eof()) {
            while (getline(triggerFile, line)) {
                std::stringstream ss(line);
                ss >> name;
                ss >> rect.left >> rect.top >> rect.width >> rect.height;
                ss >> word;
                type = triggerMap.find(word)->second;
                ss >> action;
                while (!ss.eof()) {
                    ss >> word;
                    args.push_back(word);
                }
            }
            triggers_.push_back(std::make_unique<TriggerBox>(name, rect, type, action, args));
        }
        triggerFile.close();
    }

}