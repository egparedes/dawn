//===--------------------------------------------------------------------------------*- C++ -*-===//
//                          _
//                         | |
//                       __| | __ ___      ___ ___
//                      / _` |/ _` \ \ /\ / / '_  |
//                     | (_| | (_| |\ V  V /| | | |
//                      \__,_|\__,_| \_/\_/ |_| |_| - Compiler Toolchain
//
//
//  This file is distributed under the MIT License (MIT).
//  See LICENSE.txt for details.
//
//===------------------------------------------------------------------------------------------===//

#ifndef DAWN_IIR_ACCESSCOMPUTATION_H
#define DAWN_IIR_ACCESSCOMPUTATION_H

#include "dawn/IIR/ASTFwd.h"
#include "dawn/Support/ArrayRef.h"
#include <memory>
#include <vector>

namespace dawn {

namespace iir {
class StencilInstantiation;
class StencilFunctionInstantiation;
} // namespace iir

/// @name Access computation routines
/// @ingroup optimizer
/// @{

/// @fn computeAccesses
/// @brief Compute the Accesses of `stmts`
/// @ingroup optimizer
extern void computeAccesses(iir::StencilInstantiation* instantiation,
                            ArrayRef<std::shared_ptr<iir::Stmt>> stmts);

/// @fn computeAccesses
/// @brief Compute the caller and callee Accesses of `stmts`
///
/// The caller Accesses will have the initial offset added (e.g if a stencil function is called with
/// `avg(u(i+1))` the initial offset of `u` is `[1, 0, 0]`) while the callee will not.
///
/// @see StencilFunctionInstantiation
/// @ingroup optimizer
extern void
computeAccesses(std::shared_ptr<iir::StencilFunctionInstantiation> stencilFunctionInstantiation,
                ArrayRef<std::shared_ptr<iir::Stmt>> stmts);

/// @}

} // namespace dawn

#endif
