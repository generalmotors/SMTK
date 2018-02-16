//=========================================================================
//  Copyright (c) Kitware, Inc.
//  All rights reserved.
//  See LICENSE.txt for details.
//
//  This software is distributed WITHOUT ANY WARRANTY; without even
//  the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR
//  PURPOSE.  See the above copyright notice for more information.
//=========================================================================
#include "smtk/extension/paraview/appcomponents/pqSMTKAttributePanel.h"

#include "smtk/extension/paraview/appcomponents/pqSMTKBehavior.h"
#include "smtk/extension/paraview/appcomponents/pqSMTKResource.h"

#include "smtk/view/View.h"

#include "smtk/attribute/Attribute.h"
#include "smtk/attribute/Collection.h"

#include "smtk/resource/Manager.h"
#include "smtk/resource/Resource.h"

#include "smtk/io/Logger.h"

#include "pqActiveObjects.h"
#include "pqPipelineSource.h"

#include <QPointer>
#include <QVBoxLayout>

pqSMTKAttributePanel::pqSMTKAttributePanel(QWidget* parent)
  : Superclass(parent)
  , m_attrUIMgr(nullptr)
{
  this->setObjectName("AttributeEditor");
  this->setWindowTitle("Attribute Editor");
  QWidget* w = new QWidget(this);
  this->setWidget(w);
  w->setLayout(new QVBoxLayout);
  QObject::connect(&pqActiveObjects::instance(), SIGNAL(sourceChanged(pqPipelineSource*)), this,
    SLOT(displayPipelineSource(pqPipelineSource*)));
}

pqSMTKAttributePanel::~pqSMTKAttributePanel()
{
  delete m_attrUIMgr;
}

bool pqSMTKAttributePanel::displayPipelineSource(pqPipelineSource* psrc)
{
  pqSMTKResource* rsrc = dynamic_cast<pqSMTKResource*>(psrc);
  if (rsrc)
  {
    auto attrRsrc = std::dynamic_pointer_cast<smtk::attribute::Collection>(rsrc->getResource());
    if (attrRsrc)
    {
      return this->displayResource(attrRsrc);
    }
  }
  return false;
}

bool pqSMTKAttributePanel::displayResource(smtk::attribute::CollectionPtr rsrc)
{
  bool didDisplay = false;
  if (!rsrc || rsrc == m_rsrc)
  {
    return didDisplay;
  }

  if (m_rsrc)
  {
    auto rsrcMgr = m_rsrc->manager();
    if (rsrcMgr && m_observer >= 0)
    {
      rsrcMgr->unobserve(m_observer);
    }
  }
  m_rsrc = rsrc;

  m_attrUIMgr = new smtk::extension::qtUIManager(rsrc);
  smtk::view::ViewPtr view = rsrc ? rsrc->findTopLevelView() : nullptr;
  if (view)
  {
    didDisplay = this->displayView(view);
  }
  auto rsrcMgr = rsrc->manager();
  if (rsrcMgr)
  {
    this->m_observer = rsrcMgr->observe(
      [this, rsrcMgr](smtk::resource::Event evnt, smtk::resource::Resource::Ptr attrRsrc) {
        if (evnt == smtk::resource::Event::RESOURCE_REMOVED && attrRsrc == m_rsrc)
        {
          // The application is removing the attribute collection we are viewing.
          // Clear out the panel and unobserve the manager.
          rsrcMgr->unobserve(m_observer);
          delete m_attrUIMgr;
          m_rsrc = nullptr;
        }
      });
  }
  return didDisplay;
}

bool pqSMTKAttributePanel::displayView(smtk::view::ViewPtr view)
{
  if (!view)
  {
    smtkErrorMacro(smtk::io::Logger::instance(), "Null view passed to attribute panel.");
    return false;
  }

  if (!m_attrUIMgr)
  {
    smtkErrorMacro(smtk::io::Logger::instance(), "View passed but no resource indicated.");
    return false;
  }
  auto qview = m_attrUIMgr->setSMTKView(view, this->widget());
  return qview ? true : false;
}
