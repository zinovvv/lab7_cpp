#pragma once

#include "DeleteItem.h"
#include "Album.h"
#include <string>
#include <vector>

//����� "������", �������� ������ ��������
class Artist: public DeleteItem{
private:
    std::string name;
    int numAlbums;
    std::vector<Album> albums;

public:
    //������������
    Artist(const std::string& name, int numAlbums);
    Artist(const Artist& other);
    Artist();

    //���������� ������� albums
    void SetAlbums(const std::vector<Album>& newAlbums);

    //����� ��������
    friend std::ostream& operator<<(std::ostream& os, const Artist& obj);

    //�������� �������
    void DeleteAlbum() override;

    //����������
    ~Artist() = default;
};