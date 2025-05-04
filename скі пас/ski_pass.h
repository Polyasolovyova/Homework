#ifndef SKI_PASS_H
#define SKI_PASS_H

#include <iostream>

class SkiPass {
protected:
    bool isActive;
    static int usageCount;
    static int compileCount;

public:
    SkiPass();
    virtual ~SkiPass() {}
    virtual bool usePass() = 0;
    void blockPass();
    bool isBlocked() const;
    static void incrementCompileCount();
    static int getCompileCount();
    static void incrementUsageCount();
    static int getUsageCount();
};

class SkiPassRides : public SkiPass {
private:
    int ridesLeft;

public:
    SkiPassRides(int rides);
    bool usePass() override;
};

class SkiPassUnlimited : public SkiPass {
public:
    SkiPassUnlimited();
    bool usePass() override;
};

class Turnstile {
private:
    int fraudAttempts;

public:
    Turnstile();
    bool checkPass(SkiPass& pass);
};

#endif