#ifndef CLIENSERVERECN_COMMON_HPP
#define CLIENSERVERECN_COMMON_HPP

#include <string>

static short port = 5555;

namespace Requests
{
    static const std::string Reset = "Reset";
    static const std::string getValueOfFlag = "getValue";
    static const std::string ChangeFlag = "ChangeFlag";    
    static const std::string Hello = "Hel";
    static const std::string Sale = "Sale";
    static const std::string Purchase = "Purchase";
    static const std::string ViewActive = "ViewAc";
    static const std::string ViewCompleted = "ViewComp";
    static const std::string Balance = "Bal";
    static const std::string EnterToAccount = "Enter";
    static const std::string CreateAnAccount = "Create";
    static const std::string CheckIfLoginExist = "Check";
}

#endif //CLIENSERVERECN_COMMON_HPP
