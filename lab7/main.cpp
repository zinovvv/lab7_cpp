#include "MusicLibrary.h"
#include <iostream>
#include <string>
#include <vector>
#include <iomanip>
#include <Windows.h>
#include <algorithm>

int main() {
    SetConsoleCP(1251);
    setlocale(LC_ALL, "rus");

    //Создание плейлиста(Базовый класс)
    Playlist myPlaylist("Любимые треки", 10, 0);
    //Вектор с треками для плейлиста
    std::vector<Track> tracks = {
    {"Кукушка", "Виктор Цой", 400, 1986, "рок", 12323900},
    {"Троянский конь", "ЛСП", 200, 2023, "поп хип-хоп", 709831},
    {"Монополия", "ЛСП", 198, 2023, "поп хип-хоп",694312},
    {"Несчастные люди", "ЛСП", 210, 2023, "поп хип-хоп", 902341},
    {"Вечная весна", "ЛСП", 195, 2023, "поп хип-хоп", 1003123},
    {"Ураганы", "ЛСП", 189, 2023, "поп хип-хоп", 1002492},
    {"Не убежал", "ЛСП", 240, 2023, "поп хип-хоп",1593283},
    {"Боди", "ЛСП", 200, 2023, "поп хип-хоп",1023949},
    {"Сикрет Плейс", "ЛСП", 203, 2023, "поп хип-хоп",2483921},
    {"Стоп Игра", "ЛСП", 240, 2023, "поп хип-хоп",724849}
    };
    myPlaylist.SetTracks(tracks);


    //ДЕМОНСТРАЦИЯ РАБОТЫ ПРОГРАММЫ


    Favorites favorites("Избранное", 4, 0);

    favorites.AddTrack(tracks[0]);
    favorites.AddTrack(tracks[2]);
    favorites.AddTrack(tracks[4]);
    favorites.AddTrack(tracks[6]);

    // Создаем вектор
    std::vector<Playlist> playlists;

    // Добавляем объекты в вектор
    playlists.push_back(myPlaylist);
    playlists.push_back(favorites);
    
    // Сортировка треков в плейлисте по прослушиваниям
    std::cout << "Плейлист 'Избранное' до сортировки\n" << playlists[1];
    playlists[1].SortingByListens();
    std::cout <<"Плейлист 'Избранное' после сортировки по прослушиваниям по убыванию\n" << playlists[1];

    // Поиск трека в плейлисте
    playlists[0].FindTrackByName();

    return 0;
} 