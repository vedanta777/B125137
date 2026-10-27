#include <iostream>
using namespace std;

// Base class Recommender with virtual function
class Recommender {
protected:
    int userRating;
    int popularity;
public:
    Recommender(int rating, int pop) {
        userRating = rating;
        popularity = pop;
    }
    
    virtual void generateRecommendation() {
        cout << "Base recommendation generation." << endl;
    }
};

// Derived class PersonalizedRecommender
class PersonalizedRecommender : public Recommender {
public:
    PersonalizedRecommender(int rating, int pop) : Recommender(rating, pop) {}

    // Score = 0.7 * userRating + 0.3 * popularity
    void generateRecommendation() override {
        double score = (0.7 * userRating) + (0.3 * popularity);
        cout << "Personalized Recommendation Score: " << score 
             << " (User Rating: " << userRating << ", Popularity: " << popularity << ")" << endl;
    }
};

// Derived class TrendingRecommender
class TrendingRecommender : public Recommender {
public:
    TrendingRecommender(int rating, int pop) : Recommender(rating, pop) {}

    // Score = 0.3 * userRating + 0.7 * popularity
    void generateRecommendation() override {
        double score = (0.3 * userRating) + (0.7 * popularity);
        cout << "Trending Recommendation Score: " << score 
             << " (User Rating: " << userRating << ", Popularity: " << popularity << ")" << endl;
    }
};

int main() {
    int rating, pop;
    cout << "Enter user rating (0 - 100): ";
    cin >> rating;
    cout << "Enter popularity score (0 - 100): ";
    cin >> pop;

    if (rating < 0 || rating > 100 || pop < 0 || pop > 100) {
        cout << "Error: Scores must be between 0 and 100!" << endl;
        return 1;
    }

    PersonalizedRecommender persRec(rating, pop);
    TrendingRecommender trendRec(rating, pop);

    // Base-class pointers demonstrating runtime polymorphism
    Recommender* rec1 = &persRec;
    Recommender* rec2 = &trendRec;

    cout << "\n--- AI Recommendation Engine Output ---" << endl;
    rec1->generateRecommendation(); // Calls PersonalizedRecommender's version
    rec2->generateRecommendation(); // Calls TrendingRecommender's version

    return 0;
}