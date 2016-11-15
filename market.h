#pragma once

class Market {
private:
    int     m_priceChangeMemorySize;
    double  m_currentPrice;
    double* m_priceChangeSign;

public:
    Market(double currentPrice);
    void updateMarketPrice(double excessDemand);
    double getCurrentPrice() { return m_currentPrice; }
};

