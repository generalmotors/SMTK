//=========================================================================
//  Copyright (c) Kitware, Inc.
//  All rights reserved.
//  See LICENSE.txt for details.
//
//  This software is distributed WITHOUT ANY WARRANTY; without even
//  the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR
//  PURPOSE.  See the above copyright notice for more information.
//=========================================================================
#ifndef smtk_resource_filter_Rule_h
#define smtk_resource_filter_Rule_h

#include "smtk/resource/PersistentObject.h"

#include <algorithm>

namespace smtk
{
namespace resource
{
namespace filter
{

/// A base class for filter rules.
class Rule
{
public:
  virtual ~Rule() = default;

  virtual bool operator()(const PersistentObject&) const = 0;
};

} // namespace filter
} // namespace resource
} // namespace smtk

#endif
