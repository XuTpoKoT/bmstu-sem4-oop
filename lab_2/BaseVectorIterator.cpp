#include "BaseVectorIterator.h"

BaseVectorIterator::~BaseVectorIterator()
{
}

void BaseVectorIterator::check_index () const
{
    if (index >= count) {
        auto timenow = std::chrono::system_clock::to_time_t(std::chrono::system_clock::now());
        throw IndexVectorException(ctime(&timenow), __FILE__, typeid(*this).name(), __FUNCTION__);
    }
}
