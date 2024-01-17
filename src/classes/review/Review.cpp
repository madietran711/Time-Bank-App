#include "Review.h"
using namespace std;
#include <string>

Review::Review(string reviewId, int skillRating, int supporterRating, int hostRating, Request *request)
    : reviewId(reviewId), skillRating(skillRating), supporterRating(supporterRating), hostRating(hostRating), request(request)
{
}