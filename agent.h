#pragma once

class Agent {
private:
    int     m_traderType;
    double  m_money;
    double  m_assets;

public:
    Agent();
    void randomize();
};

