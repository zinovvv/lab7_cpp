#include "Artist.h"
#include <iostream>

Artist::Artist(const std::string& name, int numAlbums)
    : name(name), numAlbums(numAlbums) {}

Artist::Artist(const Artist& other) {
    name = other.name;
    numAlbums = other.numAlbums;
    albums = other.albums;
}

Artist::Artist() {};

void Artist::SetAlbums(const std::vector<Album>& newAlbums) {
    albums = newAlbums;
}

std::ostream& operator<<(std::ostream& os, const Artist& obj) {
    for (const Album& album : obj.albums) {
        std::cout << album << std::endl;
    }
    return os;
}

void Artist::DeleteAlbum() {
    int number;
    while (true) {
        try{
            std::cout << "Введите номер альбома, который хотите удалить: " << std::endl;
            std::cin >> number;
            std::cin.ignore();
            if (number < 1 || number > albums.size()) {
                throw std::out_of_range("Некорректный номер альбома");
            }
            albums.erase(albums.begin() + number - 1);
            break;
        }
        catch (const std::out_of_range& e) {
            std::cerr << "Ошибка удаления альбома: " << e.what() << std::endl;
        }
    }
}