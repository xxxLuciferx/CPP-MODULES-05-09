#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

int main() {
    // try {
    //     Bureaucrat bureaucrat("Khalil", 42);
    //     ShrubberyCreationForm shrubberyForm;

    //     std::cout << bureaucrat << std::endl;
    //     std::cout << shrubberyForm << std::endl;

    //     bureaucrat.signForm(shrubberyForm);

    //     std::cout << shrubberyForm << std::endl;
    //     shrubberyForm.execute(bureaucrat);

    // } 
    // catch (const std::exception& e) 
    // {
    //     std::cerr << "Exception: " << e.what() << std::endl;
    // }
    // try
    // {
    //     Bureaucrat bureaucrat("correcteur", 5);
    //     RobotomyRequestForm robot_form("khalil");

    //     std::cout << bureaucrat << std::endl;
    //     std::cout << robot_form << std::endl;

    //     bureaucrat.signForm(robot_form);
    //     std::cout << robot_form << std::endl;

    //     robot_form.execute(bureaucrat);
    // }
    // catch (const std::exception& e)
    // {
    //     std::cerr << "Exception: " << e.what() << std::endl;
    // }
    // try {
    //     Bureaucrat bureaucrat("khalil", 14);
        
    //     ShrubberyCreationForm shrubberyForm("home");
    //     RobotomyRequestForm robotForm("Paper2");
    //     PresidentialPardonForm pardonForm("Paper3");

    //     std::cout << bureaucrat << std::endl;

    //     std::cout << shrubberyForm << std::endl;
    //     bureaucrat.signForm(shrubberyForm);
    //     shrubberyForm.execute(bureaucrat);

    //     std::cout << robotForm << std::endl;
    //     bureaucrat.signForm(robotForm);
    //     robotForm.execute(bureaucrat);

    //     std::cout << pardonForm << std::endl;
    //     bureaucrat.signForm(pardonForm);
    //     pardonForm.execute(bureaucrat);
    // } 
    // catch (const std::exception& e) 
    // {
    //     std::cerr << "Exception: " << e.what() << std::endl;
    // }
    try {
        Bureaucrat bureaucrat("khalil", 50);
        ShrubberyCreationForm shrubberyForm("Home");

        std::cout << bureaucrat << std::endl;
        std::cout << shrubberyForm << std::endl;

        bureaucrat.signForm(shrubberyForm);

        std::cout << shrubberyForm << std::endl;

        bureaucrat.executeForm(shrubberyForm);
    } catch (const std::exception& e) {
        std::cerr << "Exception: " << e.what() << std::endl;
    }
    return 0;
}
