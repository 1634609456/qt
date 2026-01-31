#include "password_manager.h"
#include <QInputDialog>
#include <QMessageBox>
#include <QWidget>

QString PasswordManager::storedPassword = "123"; // 权限密码

bool PasswordManager::verifyPassword(const QString& password)
{
    return password == storedPassword;
}

bool PasswordManager::showPasswordDialog(void* parent)
{
    QWidget* parentWidget = static_cast<QWidget*>(parent);
    
    bool ok;
    QString password = QInputDialog::getText(
        parentWidget,
        QObject::tr("密码验证"),
        QObject::tr("请输入密码:"),
        QLineEdit::Password,
        "",
        &ok
    );

    if (ok && !password.isEmpty()) {
        return verifyPassword(password);
    }
    return false;
}

void PasswordManager::setPassword(const QString& password)
{
    storedPassword = password;
}