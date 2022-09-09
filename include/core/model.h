#include <string>
#include <iostream>
#include <vector>
#include "image.h"

namespace naivebayes {
using namespace std;
class Model {
 public:
  std::string GetBestClass() const;
  void load();
  void calculatePriors();
  void initializeProbabilityArray();
  void calculateLikelihoods();
  void save() const;
  int convertToValue(char value);
  friend std::istream& operator >> (std::istream& is, Model &model) {
    std::string line;
    size_t counter = 0;
    vector<vector<char>> image_array(kImageSize);
    size_t line_number;
    int classifier = 0;
    while (getline(is, line)) {
        line_number = counter % (kImageSize + 1);
        if (line_number == 0) {
            classifier = stoi(line);
            continue;
        }
        for(size_t col = 0; col < kImageSize; col++) {
            image_array[line_number - 1][col] = line[col];
        }
        if (line_number == kImageSize) {
            Image new_image(classifier, image_array);
            images_.push_back(new_image);
            image_array.clear();
        }
        counter++;
    }
  }

    friend std::ostream& operator << (std::ostream& os, Model &model);


private:
    const static size_t kImageSize = 28;
    const static size_t kTotalNumbers = 10;
    const static size_t kNumShades = 3;
    const static size_t kKConst = 1;
    static vector<Image> images_;
    vector<float> prior_array_ = vector<float>(kTotalNumbers, 0.0);
    vector<int> image_counter_ = vector<int>(kTotalNumbers, 0);
    vector<vector<vector<vector<int>>>> probabilities_vector_ = vector<vector<vector<vector<int>>>>
                                                             (kImageSize, vector<vector<vector<int>>>
                                                             (kImageSize, vector<vector<int>>
                                                             (kNumShades, vector<int>
                                                             (kTotalNumbers, 0))));

};
}// namespace naivebayes
