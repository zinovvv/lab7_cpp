#pragma once

class DeleteItem {
public:
    virtual void DeleteAlbum() = 0;
    virtual ~DeleteItem() = default;
};