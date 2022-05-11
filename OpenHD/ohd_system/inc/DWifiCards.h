#ifndef WIFI_H
#define WIFI_H

#include <array>
#include <chrono>
#include <vector>

#include "DPlatform.h"

#include "json.hpp"

#include "openhd-wifi.hpp"
#include "openhd-platform.hpp"


/**
 * Discover all connected wifi cards and write them to json.
 */
class DWifiCards: public OHD::IDiscoverable  {
public:
    DWifiCards(PlatformType platform_type, BoardType board_type, CarrierType carrier_type, WiFiHotspotType wifi_hotspot_type);
    virtual ~DWifiCards() = default;
    void discover() override;
    nlohmann::json generate_manifest() override;

    void process_card(const std::string& interface_name);
private:
    std::vector<WiFiCard> m_wifi_cards;
    const PlatformType m_platform_type;
    const BoardType m_board_type;
    const CarrierType m_carrier_type;
    WiFiHotspotType m_wifi_hotspot_type;
};

#endif

