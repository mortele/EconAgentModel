#pragma once
#include <iostream>
#include <vector>

class Agent {
private:
    int             m_memorySize;
    int             m_traderType;
    double          m_money;
    double          m_assets;
    double          m_riskTakingFactor;
    double          m_wealth;
    double          m_initialWealth;
    double*         m_memory;
    class System*   m_system;

public:
    Agent(System* system);
    void randomize(double mSigma, double aSigma, double rSigma);
    static void setSigmas(double moneySigma,
                          double assetsSigma,
                          double riskTakingSigma);

    friend std::ostream& operator<<(std::ostream& os, const Agent& agent);
};

