#include "Review.h"

// Constructor
Review::Review(
    std::string reviewId,
    int skillRating,
    int supporterRating,
    int hostRating,
    Request *request,
    std::string comment)
    : reviewId(reviewId), skillRating(skillRating),
      supporterRating(supporterRating), hostRating(hostRating), request(request), comment(comment)
{
}

Review::Review(
    std::string reviewId,
    int skillRating,
    int supporterRating,

    Request *request,
    std::string comment)
    : reviewId(reviewId), skillRating(skillRating),
      supporterRating(supporterRating), request(request), comment(comment)
{
}
Review::Review(
    std::string reviewId,
    int hostRating,
    Request *request)
    : reviewId(reviewId), hostRating(hostRating), request(request)
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

std::string Review::getComment() const
{
    return comment;
}
// Setter functions

void Review::setReviewId(std::string Id)
{
    this->reviewId = Id;
}

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

void Review::setComment(std::string comment)
{
    this->comment = comment;
}