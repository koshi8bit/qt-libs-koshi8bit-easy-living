#include "operationresult.h"

OperationResult::OperationResult(bool isOk, QString message, void *value)
{
    this->isOk = isOk;
    this->message = message;
    this->value = value;
}

OperationResult::~OperationResult()
{

}

QString OperationResult::toString()
{
    return QString("%1; %2").arg(isOk).arg(message);
}