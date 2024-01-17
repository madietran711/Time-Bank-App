#include "Review.h"

// Constructor
Review::Review(
    std::string reviewId,
    int skillRating,
    int supporterRating,
    int hostRating,
    Request *request)
    : reviewId(reviewId), skillRating(skillRating),
      supporterRating(supporterRating), hostRating(hostRating), request(request)
{
}

// Destructor
Review::~Review()
{
    // Add any necessary cleanup code here
}

// Getter functions
std::string Review::getReviewId() const
{
    return reviewId;
}

int Review::getSkillRating() const
{
    return skillRating;
}

int Review::getSupporterRating() const
{
    return supporterRating;
}

int Review::getHostRating() const
{
    return hostRating;
}

Request *Review::getRequest() const
{
    return request;
}

// Setter functions
void Review::setSkillRating(int skillRating)
{
    this->skillRating = skillRating;
}

void Review::setSupporterRating(int supporterRating)
{
    this->supporterRating = supporterRating;
}

void Review::setHostRating(int hostRating)
{
    this->hostRating = hostRating;
}

void Review::setRequest(Request *request)
{
    this->request = request;
}
