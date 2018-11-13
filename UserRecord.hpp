#ifndef USER_RECORD_HPP_
#define USER_RECORD_HPP_

class UserRecord {
    // Record format :
    // Timestamp, OperationIdentifier, QuestionType, ExpectedAnswer, UserAnswer
private:
    uint32_t time_stamp_;
    OperationIdentifier operation_id_;
    QuestionType question_type_;
    int32_t expected_answer_;
    int32_t user_answer_;

public:
    UserRecord(
        OperationIdentifier id,
        QuestionType type,
        int32_t answer,
        int32_t user_answer)
    : operation_id_(id)
    , question_type_(type)
    , expected_answer_(answer)
    , user_answer_(user_answer)
    {
        // TODO
        time_stamp_ = 0;
    }
    ~UserRecord() {}
};

#endif // USER_RECORD_HPP_
