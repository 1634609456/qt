enum class UserRole {
    Guest,      // 游客
    Operator    // 操作员
};

class UserManager {
public:
    static UserManager& getInstance() {
        static UserManager instance;
        return instance;
    }
    
    void setCurrentRole(UserRole role) { current_role_ = role; }
    UserRole getCurrentRole() const { return current_role_; }
    bool isOperator() const { return current_role_ == UserRole::Operator; }

private:
    UserRole current_role_ = UserRole::Guest;
};