#ifndef TIME_BANK_APP_REVIEW_H
#define TIME_BANK_APP_REVIEW_H

#include <string>
#include "Request.h"
#include <vector>

class Review
{
private:
    std::string reviewId;

    int skillRating;
    int supporterRating;
    int hostRating;
    Request *request;

public:
    Review(
        std::string reviewId,
        int skillRating,
        int supporterRating,
        int hostRating,
        Request *request);
};

#endif