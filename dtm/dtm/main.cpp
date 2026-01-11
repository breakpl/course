#include <iostream>
#include <string>
#include <curl/curl.h>
#include "nlohmann/json.hpp"

using json = nlohmann::json;

// Callback function to write response data into a string
size_t WriteCallback(void* contents, size_t size, size_t nmemb, void* userp) {
    ((std::string*)userp)->append((char*)contents, size * nmemb);
    return size * nmemb;
}

int main() {
    CURL* curl;
    CURLcode res;
    std::string readBuffer;

    // Example API endpoint (replace with a real one, e.g., Alpha Vantage or Yahoo Finance)
    std::string url = "https://query1.finance.yahoo.com/v7/finance/quote?symbols=DT";

    curl = curl_easy_init();
    if(curl) {
        curl_easy_setopt(curl, CURLOPT_URL, url.c_str());
        curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, WriteCallback);
        curl_easy_setopt(curl, CURLOPT_WRITEDATA, &readBuffer);
        res = curl_easy_perform(curl);
        curl_easy_cleanup(curl);

        if(res == CURLE_OK) {
            try {
                json j = json::parse(readBuffer);
                double price = j["quoteResponse"]["result"][0]["regularMarketPrice"];
                std::cout << "Dynatrace (DT) Current Stock Price: " << price << " USD" << std::endl;
            } catch (...) {
                std::cerr << "Error parsing JSON response." << std::endl;
            }
        } else {
            std::cerr << "CURL request failed." << std::endl;
        }
    }
    return 0;
}
