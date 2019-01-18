//=========================================================================
//  Copyright (c) Kitware, Inc.
//  All rights reserved.
//  See LICENSE.txt for details.
//
//  This software is distributed WITHOUT ANY WARRANTY; without even
//  the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR
//  PURPOSE.  See the above copyright notice for more information.
//=========================================================================
#include "smtk/simulation/UserData.h"

namespace smtk
{
namespace simulation
{

UserData::UserData()
{
}

UserData::~UserData()
{
}

UserDataInt::UserDataInt()
  : m_value(0)
{
}

UserDataInt::~UserDataInt()
{
}

UserDataDouble::UserDataDouble()
  : m_value(0.0)
{
}

UserDataDouble::~UserDataDouble()
{
}

UserDataString::UserDataString()
{
}

UserDataString::~UserDataString()
{
}

} // namespace simulation
} // namespace smtk
