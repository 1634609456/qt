// password_manager.h
#ifndef PASSWORD_MANAGER_H
#define PASSWORD_MANAGER_H

#include <QString>

class PasswordManager
{
public:
    static bool verifyPassword(const QString& password);
    static bool showPasswordDialog(void* parent = nullptr);
    static void setPassword(const QString& password);

private:
    static QString storedPassword;
};

#endif // PASSWORD_MANAGER_H