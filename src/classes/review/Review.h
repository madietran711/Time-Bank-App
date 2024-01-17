

#ifndef TIME_BANK_APP_REVIEW_H
#define TIME_BANK_APP_REVIEW_H

#include <string>
#include "../request/Request.h"
class Request;
class Review
{
private:
    std::string reviewId;
    int skillRating;
    int supporterRating;
    int hostRating;
    Request *request;
    std::string comment;

public:
    // Constructor
    Review(
        std::string reviewId,
        int skillRating,
        int supporterRating,
        int hostRating,
        Request *request,
        std::string comment);

    // Destructor
    ~Review();

    // Getter functions
    std::string getReviewId() const;
    int getSkillRating() const;
    int getSupporterRating() const;
    int getHostRating() const;
    Request *getRequest() const;
    std::string getComment() const;

    // Setter functions
    void setSkillRating(int skillRating);
    void setSupporterRating(int supporterRating);
    void setHostRating(int hostRating);
    void setRequest(Request *request);
    void setComment(std::string comment);
};

#endif // TIME_BANK_APP_REVIEW_H
