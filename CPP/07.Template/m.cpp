#include <iostream>
#include <string>

//swap by CHAT_gpt_AI


template <class T>
T max(T& first, T& second) {
    // Use the ternary operator for concise comparison and return
    return (first > second) ? first : second;
}

template <typename T>
void swap(T& first, T& second) {
    // Efficiently swap elements using XOR swap (avoiding temporary variable)
    T temp = first;
    first ^= second;
    second ^= temp;
    second ^= temp;
}

class Person {
public:
    Person(const std::string& name, std::uint16_t age) : m_name(name), m_age(age) {}

    // Copy constructor (handle self-assignment)
    Person(const Person& personcopy) {
        m_name = personcopy.m_name;
        m_age = personcopy.m_age;
    }

    // Assignment operator (handle self-assignment)
    Person& operator=(const Person& rhs) {
        if (this != &rhs) { // Check for self-assignment
            m_name = rhs.m_name;
            m_age = rhs.m_age;
        }
        return *this;
    }

    // Overloaded comparison operator for finding the "older" Person (lexicographical order by age)
    bool operator>(const Person& rhs) const {
        return m_age > rhs.m_age;
    }

    std::string getName() const {
        return m_name;
    }

    std::uint16_t getAge() const {
        return m_age;
    }

private:
    std::string m_name;
    std::uint16_t m_age;
};

int main() {
    Person p1("Mark Shokry", 90);
    Person p2("Pola Maged", 12);

    std::cout << "Before swap: " << std::endl;
    std::cout << "P1: " << p1.getName() << "  P2: " << p2.getName() << std::endl;

    swap(p1, p2);

    std::cout << "After swap: " << std::endl;
    std::cout << "P1: " << p1.getName() << "  P2: " << p2.getName() << std::endl;

    // Find the "older" Person using the overloaded > operator
    Person olderPerson = (p1 > p2) ? p1 : p2;
    std::cout << "Older Person: " << olderPerson.getName() << " (" << olderPerson.getAge() << ")" << std::endl;

    return 0;
}
