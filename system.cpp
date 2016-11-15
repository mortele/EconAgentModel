#include "system.h"
#include "agent.h"

System::System(int numberOfAgents) {
    m_numberOfAgents = numberOfAgents;
    for (int i = 0; i < m_numberOfAgents; i++) {
        Agent* agent = new Agent();
        agent->randomize();
        m_agents.push_back(agent);
    }
}
