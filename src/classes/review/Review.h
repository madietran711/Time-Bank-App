

#ifndef TIME_BANK_APP_REVIEW_H
#define TIME_BANK_APP_REVIEW_H

#include <string>
#include "Request.h"

class Review
{
private:
    std::string reviewId;
    int skillRating;
    int supporterRating;
    int hostRating;
    Request *request;

public:
    // Constructor
    Review(
        std::string reviewId,
        int skillRating,
        int supporterRating,
        int hostRating,
        Request *request);

    // Destructor
    ~Review();

    // Getter functions
    std::string getReviewId() const;
    int getSkillRating() const;
    int getSupporterRating() const;
    int getHostRating() const;
    Request *getRequest() const;

    // Setter functions
    void setSkillRating(int skillRating);
    void setSupporterRating(int supporterRating);
    void setHostRating(int hostRating);
    void setRequest(Request *request);
};

#endif // TIME_BANK_APP_REVIEW_H
