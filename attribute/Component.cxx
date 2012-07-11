/*=========================================================================

Copyright (c) 1998-2012 Kitware Inc. 28 Corporate Drive,
Clifton Park, NY, 12065, USA.

All rights reserved. No part of this software may be reproduced, distributed,
or modified, in any form or by any means, without permission in writing from
Kitware Inc.

IN NO EVENT SHALL THE AUTHORS OR DISTRIBUTORS BE LIABLE TO ANY PARTY FOR
DIRECT, INDIRECT, SPECIAL, INCIDENTAL, OR CONSEQUENTIAL DAMAGES ARISING OUT
OF THE USE OF THIS SOFTWARE, ITS DOCUMENTATION, OR ANY DERIVATIVES THEREOF,
EVEN IF THE AUTHORS HAVE BEEN ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.

THE AUTHORS AND DISTRIBUTORS SPECIFICALLY DISCLAIM ANY WARRANTIES,
INCLUDING,
BUT NOT LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY, FITNESS FOR A
PARTICULAR PURPOSE, AND NON-INFRINGEMENT.  THIS SOFTWARE IS PROVIDED ON AN
"AS IS" BASIS, AND THE AUTHORS AND DISTRIBUTORS HAVE NO OBLIGATION TO
PROVIDE
MAINTENANCE, SUPPORT, UPDATES, ENHANCEMENTS, OR MODIFICATIONS.
=========================================================================*/


#include "attribute/Component.h"
#include "attribute/ComponentDefinition.h"

using namespace slck::attribute; 

//----------------------------------------------------------------------------
Component::Component(ComponentDefinition *def):
  m_isEnabled(true), m_definition(def)
{
}

//----------------------------------------------------------------------------
Component::~Component()
{
}
//----------------------------------------------------------------------------
const char *Component::name() const
{
  return this->m_definition->name();
}
//----------------------------------------------------------------------------
bool Component::isOptional() const
{
  return this->m_definition->isOptional();
}
//----------------------------------------------------------------------------=
bool Component::isEnabled() const
{
  return this->isOptional() ? this->m_isEnabled : true;
}
//----------------------------------------------------------------------------
bool Component::isMemberOf(const std::string &catagory) const
{
  return this->definition->isMemberOf(catagory);
}
//----------------------------------------------------------------------------
bool Component::isMemberOf(const std::vector<std::string> &catagories) const;
{
  return this->definition->isMemberOf(catagories);
}
//----------------------------------------------------------------------------
