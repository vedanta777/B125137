#include <iostream>
#include <string>
using namespace std;

class Song {
private:
    string songName;
    string artistName;
    int duration; // in seconds

public:
    // Constructor using explicit assignment
    Song(string song, string artist, int sec) {
        songName = song;
        artistName = artist;
        duration = sec;
    }

    // Friend function declaration
    friend void compareSongs(const Song &s1, const Song &s2);
};

// Friend function definition
void compareSongs(const Song &s1, const Song &s2) {
    cout << "\n--- Song Comparison ---" << endl;
    if (s1.duration > s2.duration) {
        cout << "\"" << s1.songName << "\" is longer than \"" << s2.songName << "\"." << endl;
    } else if (s2.duration > s1.duration) {
        cout << "\"" << s2.songName << "\" is longer than \"" << s1.songName << "\"." << endl;
    } else {
        cout << "Both songs have the same duration (" << s1.duration << " seconds)." << endl;
    }
}

int main() {
    string name1, artist1, name2, artist2;
    int duration1, duration2;

    cout << "Enter Song 1 Name: ";
    getline(cin, name1);
    cout << "Enter Artist 1 Name: ";
    getline(cin, artist1);
    cout << "Enter Duration 1 (seconds): ";
    cin >> duration1;
    cin.ignore();

    cout << "\nEnter Song 2 Name: ";
    getline(cin, name2);
    cout << "Enter Artist 2 Name: ";
    getline(cin, artist2);
    cout << "Enter Duration 2 (seconds): ";
    cin >> duration2;

    Song song1(name1, artist1, duration1);
    Song song2(name2, artist2, duration2);

    compareSongs(song1, song2);

    return 0;
}