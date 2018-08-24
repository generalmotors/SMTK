//=========================================================================
//  Copyright (c) Kitware, Inc.
//  All rights reserved.
//  See LICENSE.txt for details.
//
//  This software is distributed WITHOUT ANY WARRANTY; without even
//  the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR
//  PURPOSE.  See the above copyright notice for more information.
//=========================================================================

#ifndef __smtk_extensions_vtk_source_SourceFromMesh_h
#define __smtk_extensions_vtk_source_SourceFromMesh_h

#include "smtk/AutoInit.h"

#include "smtk/PublicPointerDefs.h"
#include "smtk/extension/vtk/source/Exports.h"
#include "smtk/extension/vtk/source/SourceGenerator.h"

namespace smtk
{
namespace extension
{
namespace vtk
{
namespace source
{

/// A GeneratorType for creating vtkSmartPointer<vtkAlgorithm>s
/// using smtk::resource::Resources as the key. This class extends
/// smtk::extension::vtk::source::SourceGenerator.
class VTKSMTKSOURCEEXT_EXPORT SourceFromMesh
  : public smtk::common::GeneratorType<smtk::resource::ResourcePtr, vtkSmartPointer<vtkAlgorithm>,
      SourceFromMesh>
{
public:
  bool valid(const smtk::resource::ResourcePtr&) const override;

  vtkSmartPointer<vtkAlgorithm> operator()(const smtk::resource::ResourcePtr&) override;
};
}
}
}
}

#endif
