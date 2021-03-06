//===--------------------------------------------------------------------------------*- C++ -*-===//
//                         _       _
//                        | |     | |
//                    __ _| |_ ___| | __ _ _ __   __ _
//                   / _` | __/ __| |/ _` | '_ \ / _` |
//                  | (_| | || (__| | (_| | | | | (_| |
//                   \__, |\__\___|_|\__,_|_| |_|\__, | - GridTools Clang DSL
//                    __/ |                       __/ |
//                   |___/                       |___/
//
//
//  This file is distributed under the MIT License (MIT).
//  See LICENSE.txt for details.
//
//===------------------------------------------------------------------------------------------===//

#include "gridtools/clang_dsl.hpp"

using namespace gridtools::clang;

stencil stencil {
  storage in, out;
  storage a1, a2, b1, b2, c1, c2;
  var tmp;

  Do {
    vertical_region(k_start, k_end) {
      // --- MS0 ---
      tmp = in;

      b1 = a1;
      // --- MS1 ---
      c1 = b1(k + 1);
      c1 = b1(k - 1);

      out = tmp;
      tmp = in;

      b2 = a2;
      // --- MS2 ---
      c2 = b2(k + 1);
      c2 = b2(k - 1);

      out = tmp;
    }
  }
};

int main() {}
