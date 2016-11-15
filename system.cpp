#include "system.h"
#include "agent.h"
#include "market.h"
#include <iostream>


System::System(int numberOfAgents) {
    m_market = new Market(1.0, 1.0);

    m_numberOfAgents = numberOfAgents;
    for (int i = 0; i < m_numberOfAgents; i++) {
        Agent* agent = new Agent();
        agent->randomize(10,10,0.05);
        m_agents.push_back(agent);
    }
}

void System::evolve(int steps) {
    for (int i = 0; i < steps; i++) {
        step();
    }
}

void System::step() {


}
