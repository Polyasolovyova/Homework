
#include "ski_pass.h"
#include <iostream>

int main() {
    SkiPass::incrementCompileCount();
    std::cout << "Програма була скомпільована " << SkiPass::getCompileCount() << " разів.\n";
    
    int choice;
    SkiPass* pass = nullptr;

    std::cout << "Оберіть тип SkiPass:\n";
    std::cout << "1 - 5 поїздок\n";
    std::cout << "2 - 10 поїздок\n";
    std::cout << "3 - Безлімітний\n";
    std::cin >> choice;

    if (choice == 1) {
        pass = new SkiPassRides(5);
    } else if (choice == 2) {
        pass = new SkiPassRides(10);
    } else if (choice == 3) {
        pass = new SkiPassUnlimited();
    } else {
        std::cout << "Невідомий тип перепустки!\n";
        return 1;
    }

    Turnstile turnstile;
    int action;
    do {
        std::cout << "\n1 - Використати перепустку\n2 - Перевірити статус\n0 - Вийти\n";
        std::cin >> action;
        switch (action) {
            case 1:
                turnstile.checkPass(*pass);
                break;
            case 2:
                std::cout << (pass->isBlocked() ? "Перепустка заблокована!\n" : "Перепустка активна.\n");
                break;
            case 0:
                std::cout << "Вихід.\n";
                break;
            default:
                std::cout << "Невідома дія!\n";
        }
    } while (action != 0);

    delete pass;
    return 0;
}