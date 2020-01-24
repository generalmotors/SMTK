//=============================================================================
//
//  Copyright (c) Kitware, Inc.
//  All rights reserved.
//  See LICENSE.txt for details.
//
//  This software is distributed WITHOUT ANY WARRANTY; without even
//  the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR
//  PURPOSE.  See the above copyright notice for more information.
//
//=============================================================================
#include "smtk/extension/qt/qtViewRegistrar.h"

#include "smtk/extension/qt/qtAnalysisView.h"
#include "smtk/extension/qt/qtAssociationView.h"
#include "smtk/extension/qt/qtAttributeView.h"
#include "smtk/extension/qt/qtCategorySelectorView.h"
#include "smtk/extension/qt/qtGroupView.h"
#include "smtk/extension/qt/qtInstancedView.h"
#include "smtk/extension/qt/qtModelEntityAttributeView.h"
#include "smtk/extension/qt/qtOperationView.h"
#include "smtk/extension/qt/qtResourceBrowser.h"
#include "smtk/extension/qt/qtSelectorView.h"

#include <tuple>

namespace smtk
{
namespace extension
{
namespace
{
typedef std::tuple<qtAnalysisView, qtAssociationView, qtAttributeView, qtCategorySelectorView,
  qtGroupView, qtInstancedView, qtModelEntityAttributeView, qtOperationView, qtResourceBrowser,
  qtSelectorView>
  ViewWidgetList;
}

void qtViewRegistrar::registerTo(const smtk::view::Manager::Ptr& viewManager)
{
  viewManager->registerViewWidgets<ViewWidgetList>();
  // a set of legacy constructor names to use for alternate lookup.
  std::map<std::string, std::string> altNames = {
    { "Analysis", "qtAnalysisView" }, { "Associations", "qtAssociationView" },
    { "Attribute", "qtAttributeView" }, { "Group", "qtGroupView" },
    { "Instanced", "qtInstancedView" }, { "Operation", "qtOperationView" },
    { "Selector", "qtSelectorView" }, { "SimpleExpression", "qtSimpleExpressionView" },
    { "Category", "qtCategorySelectorView" }, { "ModelEntity", "qtModelEntityAttributeView" },
    { "ResourceBrowser", "qtResourceBrowser" },
  };
  viewManager->addWidgetAliases(altNames);
}

void qtViewRegistrar::unregisterFrom(const smtk::view::Manager::Ptr& viewManager)
{
  viewManager->unregisterViewWidgets<ViewWidgetList>();
}
}
}