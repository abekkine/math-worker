#ifndef USER_STATS_HPP_
#define USER_STATS_HPP_

#include "UserRecord.hpp"

class UserStats {
private:
    int user_id_;
    std::vector<UserRecord *> records_;

public:
    UserStats(int id)
    : user_id_(id)
    {}
    ~UserStats() {}
    void AddRecord(UserRecord * record) {
        records_.push_back(record);
    }
    void GetRecords() {
        // TODO
    }
};

#endif // USER_STATS_HPP_
