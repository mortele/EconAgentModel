#pragma once
#include <vector>

class System {
private:
    int                         m_numberOfAgents;
    class Market*               m_market;
    std::vector<class Agent*>   m_agents;

    void step();

public:
    System(int numberOfAgents);
    double getCurrentMarketPrice() { return m_market->getCurrentPrice(); }
    void evolve(int steps);
};

