#include <string>

class Patient {
private:
    std::string name;
    char category;

public:
    
    Patient( std::string name, char category) : name(name), category(category) {}

    
    std::string getName() {
        return name;
    }

    char getCategory() const {
        return category;
    }
};
