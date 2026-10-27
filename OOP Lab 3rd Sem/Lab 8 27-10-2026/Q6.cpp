#include <iostream>
using namespace std;

// Base class SecurityScanner
class SecurityScanner {
protected:
    int threats;
public:
    SecurityScanner(int t) {
        threats = t;
    }
    
    virtual void scan() {
        cout << "Base security scan." << endl;
    }
};

// Derived class BasicScanner
class BasicScanner : public SecurityScanner {
public:
    BasicScanner(int t) : SecurityScanner(t) {}

    // Reports the number of threats detected
    void scan() override {
        cout << "Basic Scanner -> Threats Detected: " << threats << endl;
    }
};

// Derived class AdvancedScanner
class AdvancedScanner : public SecurityScanner {
public:
    AdvancedScanner(int t) : SecurityScanner(t) {}

    // Reports detected threats and remaining threats after removing 90%[cite: 2]
    void scan() override {
        int remaining = threats - (threats * 0.90);
        cout << "Advanced Scanner -> Threats Detected: " << threats 
             << ", Threats Remaining after 90% removal: " << remaining << endl;
    }
};

int main() {
    int t;
    cout << "Enter number of threats detected: ";
    cin >> t;

    BasicScanner basic(t);
    AdvancedScanner advanced(t);

    cout << "\n--- Security Scan Reports ---" << endl;
    basic.scan();
    advanced.scan();

    return 0;
}