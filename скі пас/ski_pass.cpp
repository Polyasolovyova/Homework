#include "ski_pass.h"

int SkiPass::usageCount = 0;
int SkiPass::compileCount = 0;

SkiPass::SkiPass() : isActive(true) {}
void SkiPass::blockPass() { isActive = false; }
bool SkiPass::isBlocked() const { return !isActive; }

void SkiPass::incrementCompileCount() {
    compileCount++;
}

int SkiPass::getCompileCount() {
    return compileCount;
}

void SkiPass::incrementUsageCount() {
    usageCount++;
}

int SkiPass::getUsageCount() {
    return usageCount;
}

SkiPassRides::SkiPassRides(int rides) : ridesLeft(rides) {}
bool SkiPassRides::usePass() {
    if (!isActive || ridesLeft <= 0 || SkiPass::getUsageCount() >= 6) return false;
    ridesLeft--;
    SkiPass::incrementUsageCount();
    return true;
}

SkiPassUnlimited::SkiPassUnlimited() { isActive = true; }
bool SkiPassUnlimited::usePass() {
    if (SkiPass::getUsageCount() >= 6) return false;
    SkiPass::incrementUsageCount();
    return isActive;
}

Turnstile::Turnstile() : fraudAttempts(0) {}
bool Turnstile::checkPass(SkiPass& pass) {
    if (pass.isBlocked() || SkiPass::getUsageCount() >= 6) {
        std::cout << "Квиток заблоковано! Доступ заборонено.\n";
        return false;
    }
    if (pass.usePass()) {
        std::cout << "Прохід дозволено.\n";
        return true;
    } else {
        fraudAttempts++;
        std::cout << "Недостатньо прав для проходу!\n";
        if (fraudAttempts >= 3) {
            std::cout << "Спроба обману! Квиток блокується.\n";
            pass.blockPass();
        }
        return false;
    }
}

