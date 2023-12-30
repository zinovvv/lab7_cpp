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

    //�������� ���������(������� �����)
    Playlist myPlaylist("������� �����", 10, 0);
    //������ � ������� ��� ���������
    std::vector<Track> tracks = {
    {"�������", "������ ���", 400, 1986, "���", 12323900},
    {"��������� ����", "���", 200, 2023, "��� ���-���", 709831},
    {"���������", "���", 198, 2023, "��� ���-���",694312},
    {"���������� ����", "���", 210, 2023, "��� ���-���", 902341},
    {"������ �����", "���", 195, 2023, "��� ���-���", 1003123},
    {"�������", "���", 189, 2023, "��� ���-���", 1002492},
    {"�� ������", "���", 240, 2023, "��� ���-���",1593283},
    {"����", "���", 200, 2023, "��� ���-���",1023949},
    {"������ �����", "���", 203, 2023, "��� ���-���",2483921},
    {"���� ����", "���", 240, 2023, "��� ���-���",724849}
    };
    myPlaylist.SetTracks(tracks);


    //������������ ������ ���������


    Favorites favorites("���������", 4, 0);

    favorites.AddTrack(tracks[0]);
    favorites.AddTrack(tracks[2]);
    favorites.AddTrack(tracks[4]);
    favorites.AddTrack(tracks[6]);

    // ������� ������
    std::vector<Playlist> playlists;

    // ��������� ������� � ������
    playlists.push_back(myPlaylist);
    playlists.push_back(favorites);
    
    // ���������� ������ � ��������� �� ��������������
    std::cout << "�������� '���������' �� ����������\n" << playlists[1];
    playlists[1].SortingByListens();
    std::cout <<"�������� '���������' ����� ���������� �� �������������� �� ��������\n" << playlists[1];

    // ����� ����� � ���������
    playlists[0].FindTrackByName();

    return 0;
} 