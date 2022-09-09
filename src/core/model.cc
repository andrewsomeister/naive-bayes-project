#include <core/model.h>
#include <core/image.h>
#include <iostream>
#include <fstream>

using namespace std;

namespace naivebayes {

std::string Model::GetBestClass() const {
  return "CS 126";
}

std::ostream& operator << (std::ostream& os, Model &model) {
    for (size_t classifier = 0; classifier < kTotalNumbers; classifier++) {
        for(size_t shade = 0; shade < kNumShades; shade++) {
            for (size_t row = 0; row < kImageSize; row++) {
                for (size_t col = 0; col < kImageSize; col++) {
                    float probability = (kKConst + probabilities_vector_[row][col][classifier][shade])
                                        / (kKConst * kNumShades + image_counter_[classifier]);
                    probabilities_vector_[row][col][classifier][shade] = probability;
                }
            }
        }
    }
}

void Model::calculatePriors() {
    size_t total_images = 0;
    for (Image image: images_) {
        prior_array_[image.getClass()]++;
        image_counter_[image.getClass()]++;
        total_images++;
    }
    for (float &value: prior_array_) {
        value = value / total_images;
    }
}

int Model::convertToValue(char value) {
    if (value == '#') {
        return 2;
    } else if (value == '+') {
        return 1;
    } else {
        return 0;
    }
}

void Model::initializeProbabilityArray() {
    for (Image image: images_) {
        for(size_t shade = 0; shade < kNumShades; shade++) {
            for (size_t row = 0; row < kImageSize; row++) {
                for (size_t col = 0; col < kImageSize; col++) {
                    if (shade == convertToValue(image.getValues()[row][col])) {
                        probabilities_vector_[row][col][image.getClass()][shade]++;
                    }
                }
            }
        }
    }
}

void Model::calculateLikelihoods() {
    for (size_t classifier = 0; classifier < kTotalNumbers; classifier++) {
        for(size_t shade = 0; shade < kNumShades; shade++) {
            for (size_t row = 0; row < kImageSize; row++) {
                for (size_t col = 0; col < kImageSize; col++) {
                    float probability = (kKConst + probabilities_vector_[row][col][classifier][shade])
                            / (kKConst * kNumShades + image_counter_[classifier]);
                    probabilities_vector_[row][col][classifier][shade] = probability;
                }
            }
        }
    }
}

void Model::load() {
    calculatePriors();
    initializeProbabilityArray();
    calculateLikelihoods();
}

void Model::save() const {
    std::ofstream output_file("../data/trainedmodel.txt");
        output_file << "Some text" << std::endl;
        output_file << "A";
        output_file << "B" << std::endl;
}


}  // namespace naivebayes