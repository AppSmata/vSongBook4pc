#ifndef ASEXCEPTION_H
#define ASEXCEPTION_H

#include <QString>

class AsException {
    QString _message;

public:
    AsException(const QString& message) : _message(message) {}
    QString message() const {
        return "Exception: " + _message;
    }
};

#endif
