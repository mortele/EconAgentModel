#include "agent.h"
#include "system.h"
#include "RandomNumberGenerator/random.h"
#include <cmath>

void Agent::randomizeMemory() {
    double total = 0;
    for (int i = 0; i < m_memorySize; i++) {
        const double r = Random::nextDouble(-1.0, 1.0);
        total += r;
        m_memory[i] = r;
    }
    const double oneOverTotal = 1.0 / total;
    for (int i = 0; i< m_memorySize; i++) {
        m_memory[i] *= oneOverTotal;
    }
}

Agent::Agent(System* system) {
    m_system            = system;
    m_traderType        = 0;
    m_money             = 0;
    m_assets            = 0;
    m_riskTakingFactor  = 0;
    m_wealth            = 0;
    m_memorySize        = 10;
    m_memory            = new double[m_memorySize];
}

void Agent::randomize(double mSigma, double aSigma, double rSigma) {
    m_traderType = Random::nextInt(0,1);
    m_money      = std::fabs(Random::nextGaussian(0, mSigma));
    m_assets     = std::fabs(Random::nextGaussian(0, aSigma));
    m_riskTakingFactor = std::fabs(Random::nextGaussian(0, rSigma));
    m_riskTakingFactor = (m_riskTakingFactor < 0.01) ? 0.01 : m_riskTakingFactor;
    m_wealth        = m_money + m_assets * m_system->getCurrentMarketPrice();
    m_initialWealth = m_wealth;
    randomizeMemory();
}

std::ostream& operator<<(std::ostream& os, const Agent& agent) {
    os      << agent.m_traderType << " "
            << agent.m_money << " "
            << agent.m_assets << " "
            << agent.m_riskTakingFactor;
    return os;
}
