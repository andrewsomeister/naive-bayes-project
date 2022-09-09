#include <iostream>
#include <core/model.h>
#include <fstream>

int main() {
    std::ifstream input_file("../data/trainingimagesandlabels.txt");
    naivebayes::Model model;
    input_file >> model;
}
