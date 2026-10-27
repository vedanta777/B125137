#include <iostream>
using namespace std;

// Base class Compressor
class Compressor {
protected:
    double fileSize;
public:
    Compressor(double size) {
        fileSize = size;
    }
    
    virtual void compress() {
        cout << "Base compression method." << endl;
    }
};

// Derived class TextCompressor
class TextCompressor : public Compressor {
public:
    TextCompressor(double size) : Compressor(size) {}

    // Text files retain 40% of their original size
    void compress() override {
        double compressedSize = fileSize * 0.40;
        cout << "Text File -> Original Size: " << fileSize 
             << " MB, Compressed Size: " << compressedSize << " MB" << endl;
    }
};

// Derived class ImageCompressor
class ImageCompressor : public Compressor {
public:
    ImageCompressor(double size) : Compressor(size) {}

    // Image files retain 70% of their original size
    void compress() override {
        double compressedSize = fileSize * 0.70;
        cout << "Image File -> Original Size: " << fileSize 
             << " MB, Compressed Size: " << compressedSize << " MB" << endl;
    }
};

int main() {
    double size;
    cout << "Enter file size in MB: ";
    cin >> size;

    TextCompressor tc(size);
    ImageCompressor ic(size);

    cout << "\n--- Compression Results ---" << endl;
    tc.compress();
    ic.compress();

    return 0;
}