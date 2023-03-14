// Copyright (c) 2022 PaddlePaddle Authors. All Rights Reserved.
//
// Licensed under the Apache License, Version 2.0 (the "License");
// you may not use this file except in compliance with the License.
// You may obtain a copy of the License at
//
//     http://www.apache.org/licenses/LICENSE-2.0
//
// Unless required by applicable law or agreed to in writing, software
// distributed under the License is distributed on an "AS IS" BASIS,
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
// See the License for the specific language governing permissions and
// limitations under the License.

#pragma once

#include "paddle/phi/core/dense_tensor.h"
#include "paddle/phi/core/device_context.h"
#include "paddle/phi/core/device_context.h"
#include "paddle/phi/common/float16.h"
#include "paddle/phi/common/bfloat16.h"

namespace phi {

template <typename T, typename Context>
void UnfoldKernel(const Context& ctx,
                  const DenseTensor& x,
                  const std::vector<int>& kernel_sizes,
                  const std::vector<int>& strides,
                  const std::vector<int>& paddings,
                  const std::vector<int>& dilations,
                  DenseTensor* out);

}  // namespace phi

PD_REGISTER_KERNEL(unfold, GPU, ALL_LAYOUT, phi::UnfoldKernel, float, double, phi::dtype::float16, phi::dtype::bfloat16) {}
