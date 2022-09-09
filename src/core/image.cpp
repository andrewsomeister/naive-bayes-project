#include <vector>
#include <core/image.h>
using namespace std;
namespace naivebayes {
    Image::Image(int classifier, vector<vector<char>> values) {
        values_ = values;
        classifier_ = classifier;
    }

    int Image::getClass() const {
        return classifier_;
    }
    vector<vector<char>> Image::getValues() const {
        return values_;
    }

}
