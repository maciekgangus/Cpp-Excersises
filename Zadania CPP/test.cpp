#include <iostream>
#include <vector>
#include <typeinfo>

class Employee {
public:
    virtual void work() {
        std::cout << "Employee working" << std::endl;
    }
    virtual ~Employee() {}
};

class Engineer : virtual public Employee {
public:
    void work() override {
        std::cout << "Engineer designing" << std::endl;
    }
    void developSoftware() {
        std::cout << "Engineer developing software" << std::endl;
    }
};

class Manager : virtual public Employee {
public:
    void work() override {
        std::cout << "Manager managing team" << std::endl;
    }
    void conductMeeting() {
        std::cout << "Manager conducting meeting" << std::endl;
    }
};

class TeamLeader : public Engineer, public Manager {
public:
    void work() override {
        std::cout << "TeamLeader leading team" << std::endl;
    }
    void leadProject() {
        std::cout << "TeamLeader leading project" << std::endl;
    }
};

void performDuties(Employee* emp) {
    emp->work();

    // Sprawdzenie, czy emp jest typu Engineer
    if (Engineer* eng = dynamic_cast<Engineer*>(emp)) {
        eng->developSoftware();
    }

    // Sprawdzenie, czy emp jest typu Manager
    if (Manager* mgr = dynamic_cast<Manager*>(emp)) {
        mgr->conductMeeting();
    }

    // Sprawdzenie, czy emp jest typu TeamLeader
    if (TeamLeader* leader = dynamic_cast<TeamLeader*>(emp)) {
        leader->leadProject();
    }
}

int main() {
    std::vector<Employee*> employees;

    Employee emp;
    Engineer eng;
    Manager mgr;
    TeamLeader leader;

    employees.push_back(&emp);
    employees.push_back(&eng);
    employees.push_back(&mgr);
    employees.push_back(&leader);

    for (Employee* e : employees) {
        performDuties(e);
        std::cout << std::endl;
    }

    return 0;
}