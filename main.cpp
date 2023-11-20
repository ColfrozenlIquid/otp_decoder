#include <iostream>
#include <cstdlib>
#include <string>
#include <vector>
std::vector<int> string_to_int_vec(std::string);
int main() {
    std::string cypher  = "04 10 12 00 01 08 67 0A 19 65 0F 03 0A 00 ";
    std::string key1    = "45 44 46 41 42 43 47 4B 4D 45 4B 42 5D 4E ";
    std::string key2    = "45 44 46 41 42 43 47 4B 4D 45 41 4C 45 4E ";
    std::vector<int> cypher_vector = string_to_int_vec(cypher);    
    std::vector<int> key1_vector = string_to_int_vec(key1);
    std::vector<int> key2_vector = string_to_int_vec(key2);
    std::string result1;
    std::string result2;
    for (int i = 0; i < cypher_vector.size(); i++) {
        int res1 = key1_vector[i] ^ cypher_vector[i];
        int res2 = key2_vector[i] ^ cypher_vector[i];
        result1.push_back(res1);
        result2.push_back(res2);
    }
    std::cout << "(C ^ K1): " << result1 << std::endl;
    std::cout << "(C ^ K2): " << result2 << std::endl;
    return 0;
}

std::vector<int> string_to_int_vec(std::string input_string) {
    std::vector<int> result;
    for (int i = 0; i < input_string.length(); i++) {
        if (input_string[i] == ' '){
            std::string hex = "";
            hex.push_back(input_string[i-2]);
            hex.push_back(input_string[i-1]);
            signed character = std::stoi(hex, nullptr, 16);
            result.push_back(character);
        }
    }
    return result;
}