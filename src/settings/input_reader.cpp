#include "settings/input_reader.h"

std::list<Keybind> make_keybinds(std::string path){
    std::list<Keybind> keybinds = std::list<Keybind>();
    std::ifstream key_config;
    key_config.open(path);
    if(!key_config){
        std::cerr << "Error : input config file missing" << std::endl;
        exit(1);
    }
    std::string line;
    while (std::getline(key_config, line)){
        if (line.length() > 1 && line.substr(0, 2) == "A0"){
            read_player_input(keybinds, key_config);
        }   
    }
    
    return keybinds;
}

void read_player_input(std::list<Keybind>& keybinds, std::ifstream& file){
    std::string line;
    int nb_players = 0; 
    //TODO : max number of players become a "global" constant
    while (nb_players < 2 && std::getline(file, line))
    {
        if (line.length() > 2 && line.substr(0, 2) == "A0"){ //TODO : not amazing
            for (int i = 0; i < 6; i++){
                std::getline(file, line);
                keybinds.push_back(Keybind{key_of_string(line), UniversalInput{nb_players, i}});
            }
            nb_players++;
        }
    }
    if (nb_players != 2){
        std::cerr << "Some players miss some outputs" << std::endl;
        exit(1);
    }
}

sf::Keyboard::Key key_of_string(std::string str){
    switch (str[0])
    {
    case 'A':
        return sf::Keyboard::Key::A;
    case 'B':
        return sf::Keyboard::Key::B;
    case 'C':
        return sf::Keyboard::Key::C;
    case 'D':
        return sf::Keyboard::Key::D;
    case 'E':
        return sf::Keyboard::Key::E;
    case 'F':
        return sf::Keyboard::Key::F;
    case 'G':
        return sf::Keyboard::Key::G;
    case 'H':
        return sf::Keyboard::Key::H;
    case 'I':
        return sf::Keyboard::Key::I;
    case 'J':
        return sf::Keyboard::Key::J;
    case 'K':
        return sf::Keyboard::Key::K;
    case 'L':
        return sf::Keyboard::Key::L;
    case 'M':
        return sf::Keyboard::Key::M;
    case 'N':
        return sf::Keyboard::Key::N;
    case 'O':
        return sf::Keyboard::Key::O;
    case 'P':
        return sf::Keyboard::Key::P;
    case 'Q':
        return sf::Keyboard::Key::Q;
    case 'R':
        return sf::Keyboard::Key::R;
    case 'S':
        return sf::Keyboard::Key::S;
    case 'T':
        return sf::Keyboard::Key::T;
    case 'U':
        return sf::Keyboard::Key::U;
    case 'V':
        return sf::Keyboard::Key::V;
    case 'W':
        return sf::Keyboard::Key::W;
    case 'X':
        return sf::Keyboard::Key::X;
    case 'Y':
        return sf::Keyboard::Key::Y;
    case 'Z':
        return sf::Keyboard::Key::Z;
    default:
        if(str.length() >=5 && str.substr(0, 5) == "SPACE")
            return sf::Keyboard::Key::Space;
        std::cerr << "Unrecognised line " << str << std::endl; //TODO : specify line number
        std::abort();
    }
}
