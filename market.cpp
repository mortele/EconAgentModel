#include "market.h"
#include <cmath>

Market::Market(double currentPrice, double fundamentalPrice) {
    m_priceChangeMemorySize = 100;
    m_currentPrice          = currentPrice;
    m_priceChangeSign       = new double[m_priceChangeMemorySize];
    for (int i = 0; i < m_priceChangeMemorySize; i++) {
        m_priceChangeSign[i] = 0;
    }
}

void Market::updateMarketPrice(double excessDemand) {
    m_currentPrice = m_currentPrice * exp(excessDemand);

    // Shift all the sign "memories" one back.
    for (int i = 0; i < m_priceChangeMemorySize-1; i++) {
        m_priceChangeSign[i] = m_priceChangeSign[i+1];
    }

    double currentSign  = (excessDemand > 0) ? 1 : -1;
    m_priceChangeSign[m_priceChangeMemorySize-1] = currentSign;
}
