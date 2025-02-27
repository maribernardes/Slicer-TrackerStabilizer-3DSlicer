/*==============================================================================

  Program: 3D Slicer

  Portions (c) Copyright Brigham and Women's Hospital (BWH) All Rights Reserved.

  See COPYRIGHT.txt
  or http://www.slicer.org/copyright/copyright.txt for details.

  Unless required by applicable law or agreed to in writing, software
  distributed under the License is distributed on an "AS IS" BASIS,
  WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
  See the License for the specific language governing permissions and
  limitations under the License.

==============================================================================*/

// Qt includes
#include <QtPlugin>

// TrackerStabilizer Logic includes
#include <vtkSlicerTrackerStabilizerLogic.h>

// TrackerStabilizer includes
#include "qSlicerTrackerStabilizerModule.h"
#include "qSlicerTrackerStabilizerModuleWidget.h"

//-----------------------------------------------------------------------------
// Migration VTK7-Qt4-to-VTK8-Qt5
// Q_EXPORT_PLUGIN2(qSlicerTrackerStabilizerModule, qSlicerTrackerStabilizerModule);

#if (QT_VERSION < QT_VERSION_CHECK(5, 0, 0))
#include <QtPlugin>
Q_EXPORT_PLUGIN2(qSlicerTrackerStabilizerModule, qSlicerTrackerStabilizerModule);
#endif

//-----------------------------------------------------------------------------
/// \ingroup Slicer_QtModules_ExtensionTemplate
class qSlicerTrackerStabilizerModulePrivate
{
public:
  qSlicerTrackerStabilizerModulePrivate();
};

//-----------------------------------------------------------------------------
// qSlicerTrackerStabilizerModulePrivate methods

//-----------------------------------------------------------------------------
qSlicerTrackerStabilizerModulePrivate::qSlicerTrackerStabilizerModulePrivate()
{
}

//-----------------------------------------------------------------------------
// qSlicerTrackerStabilizerModule methods

//-----------------------------------------------------------------------------
qSlicerTrackerStabilizerModule::qSlicerTrackerStabilizerModule(QObject* _parent)
  : Superclass(_parent)
  , d_ptr(new qSlicerTrackerStabilizerModulePrivate)
{
}

//-----------------------------------------------------------------------------
qSlicerTrackerStabilizerModule::~qSlicerTrackerStabilizerModule()
{
}

//-----------------------------------------------------------------------------
QString qSlicerTrackerStabilizerModule::helpText() const
{
  return "This module smooth linear transforms by applying a low-pass filter";
}

//-----------------------------------------------------------------------------
QString qSlicerTrackerStabilizerModule::acknowledgementText() const
{
  return "This work was partially funded by NIH grant NXNNXXNNNNNN-NNXN";
}

//-----------------------------------------------------------------------------
QStringList qSlicerTrackerStabilizerModule::contributors() const
{
  QStringList moduleContributors;
  moduleContributors << QString("Laurent Chauvin (BWH), Jayender Jagadeesan (BWH), Andras Lasso (Queen's University)");
  return moduleContributors;
}

//-----------------------------------------------------------------------------
QIcon qSlicerTrackerStabilizerModule::icon() const
{
  return QIcon(":/Icons/TrackerStabilizer.png");
}

//-----------------------------------------------------------------------------
QStringList qSlicerTrackerStabilizerModule::categories() const
{
  return QStringList() << "IGT";
}

//-----------------------------------------------------------------------------
QStringList qSlicerTrackerStabilizerModule::dependencies() const
{
  return QStringList();
}

//-----------------------------------------------------------------------------
void qSlicerTrackerStabilizerModule::setup()
{
  this->Superclass::setup();
}

//-----------------------------------------------------------------------------
qSlicerAbstractModuleRepresentation* qSlicerTrackerStabilizerModule
::createWidgetRepresentation()
{
  return new qSlicerTrackerStabilizerModuleWidget;
}

//-----------------------------------------------------------------------------
vtkMRMLAbstractLogic* qSlicerTrackerStabilizerModule::createLogic()
{
  return vtkSlicerTrackerStabilizerLogic::New();
}
