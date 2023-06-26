#include "Playlist.h"

void Playlist::addSong(std::string name, std::string artist) {
    this->songList->addNode((Song {name, artist}));
}

void Playlist::removeSong(Song song) {
    this->songList->removeNode(song);
}

void Playlist::printPlaylist() {
    this->songList->printList();
}
