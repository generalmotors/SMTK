//=========================================================================
//  Copyright (c) Kitware, Inc.
//  All rights reserved.
//  See LICENSE.txt for details.
//
//  This software is distributed WITHOUT ANY WARRANTY; without even
//  the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR
//  PURPOSE.  See the above copyright notice for more information.
//=========================================================================
#include "smtk/extension/qt/qtComponentItem.h"
#include "smtk/extension/qt/qtReferenceItemData.h"

#include "smtk/extension/qt/qtBaseView.h"
#include "smtk/extension/qt/qtUIManager.h"

#include "smtk/attribute/ComponentItem.h"
#include "smtk/attribute/ComponentItemDefinition.h"

namespace smtk
{
namespace extension
{

class qtComponentItem::Internal
{
public:
};

qtComponentItem::qtComponentItem(
  smtk::attribute::ComponentItemPtr item, QWidget* p, qtBaseView* bview, Qt::Orientation enumOrient)
  : Superclass(std::static_pointer_cast<smtk::attribute::Item>(item), p, bview)
{
  (void)enumOrient;
  m_p = new Internal;
  this->createWidget();
}

qtComponentItem::~qtComponentItem()
{
  delete m_p;
}

void qtComponentItem::setLabelVisible(bool visible)
{
  qtReferenceItem::m_p->m_label->setVisible(visible);
}

smtk::attribute::ComponentItemPtr qtComponentItem::componentItem()
{
  return std::static_pointer_cast<smtk::attribute::ComponentItem>(this->getObject());
}

void qtComponentItem::updateItemData()
{
}

void qtComponentItem::createWidget()
{
  // Let our subclass do the UI work.
  this->Superclass::createWidget();

  // Now add in ComponentItem specifics.
  smtk::attribute::ItemPtr dataObj = this->getObject();
  if (!dataObj || !this->passAdvancedCheck() ||
    (this->baseView() &&
      !this->baseView()->uiManager()->passItemCategoryCheck(dataObj->definition())))
  {
    return;
  }

  this->updateItemData();
}
}
}
