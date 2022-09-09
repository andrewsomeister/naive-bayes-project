#include <string>
#include <iostream>
#include <vector>
using namespace std;
namespace naivebayes {
    class Image {

    public:
        Image(int classifier, vector<vector<char>> values);

        int getClass() const;
        vector<vector<char>> getValues() const;

        void initializeImage(vector<vector<int>> image);

    private:
        int classifier_;
        vector<vector<char>> values_;

    };
}
#ifndef NAIVE_BAYES_IMAGE_H
#define NAIVE_BAYES_IMAGE_H

#endif //NAIVE_BAYES_IMAGE_H
