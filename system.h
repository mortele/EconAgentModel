#pragma once
#include <vector>

class System {
private:
    int                         m_numberOfAgents;
    class Market*               m_market;
    std::vector<class Agent*>   m_agents;

public:
    System(int numberOfAgents);

};

