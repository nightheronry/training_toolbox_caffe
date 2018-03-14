#ifndef CAFFE_REORG_YOLO_LAYER_HPP_
#define CAFFE_REORG_YOLO_LAYER_HPP_

#include <vector>

#include "caffe/blob.hpp"
#include "caffe/layer.hpp"
#include "caffe/proto/caffe.pb.h"

namespace caffe {

/**
 * @brief Reorg yolo
 */
template <typename Dtype>
class ReorgYoloLayer : public Layer<Dtype> {
 public:
  explicit ReorgYoloLayer(const LayerParameter& param) : Layer<Dtype>(param) {
  }

  virtual void LayerSetUp(const vector<Blob<Dtype>*>& bottom,
                          const vector<Blob<Dtype>*>& top);

  virtual void Reshape(const vector<Blob<Dtype>*>& bottom,
                       const vector<Blob<Dtype>*>& top);

  virtual inline const char* type() const {
    return "ReorgYolo";
  }
  virtual inline int ExactNumBottomBlobs() const {
    return 1;
  }
  virtual inline int ExactNumTopBlobs() const {
    return 1;
  }

 protected:
  virtual void Forward_cpu(const vector<Blob<Dtype>*>& bottom,
                           const vector<Blob<Dtype>*>& top);

  virtual void Backward_cpu(const vector<Blob<Dtype>*>& top,
                            const vector<bool>& propagate_down,
                            const vector<Blob<Dtype>*>& bottom);

  int stride_;
};

}  // namespace caffe

#endif  // CAFFE_REORG_YOLO_LAYER_HPP_