#include "vertex_line3d.h"
#include <stdio.h>

#ifdef WINDOWS
#include <windows.h>
#endif

#ifdef G2O_HAVE_OPENGL
#ifdef __APPLE__
#include <OpenGL/gl.h>
#else
#include <GL/gl.h>
#endif
#endif

#include <typeinfo>

namespace Slam3dAddons {
  using namespace g2o;

  bool VertexLine3D::read(std::istream& is) {
    Vector6d lv;
    for (int i=0; i<6; i++)
      is >> lv[i];
    setEstimate(Line3D(lv));
    return true;
  }

  bool VertexLine3D::write(std::ostream& os) const {
    Vector6d lv=_estimate;
    for (int i=0; i<6; i++){
      os << lv[i] << " ";
    }
    return os.good();
  }

// #ifdef G2O_HAVE_OPENGL
//   void drawTriangle(float xSize, float ySize);

//   VertexLine3DDrawAction::VertexLine3DDrawAction(): DrawAction(typeid(VertexLine3D).name()){
//   }

//   bool VertexLine3DDrawAction::refreshPropertyPtrs(HyperGraphElementAction::Parameters* params_){
//     if (!DrawAction::refreshPropertyPtrs(params_))
//       return false;
//     if (_previousParams){
//       _planeWidth = _previousParams->makeProperty<FloatProperty>(_typeName + "::PLANE_WIDTH", 3);
//       _planeHeight = _previousParams->makeProperty<FloatProperty>(_typeName + "::PLANE_HEIGHT", 3);
//     } else {
//       _planeWidth = 0;
//       _planeHeight = 0;
//     }
//     return true;
//   }

//   HyperGraphElementAction* VertexLine3DDrawAction::operator()(HyperGraph::HyperGraphElement* element, 
//                  HyperGraphElementAction::Parameters* params_){
//     if (typeid(*element).name()!=_typeName)
//       return 0;

//     refreshPropertyPtrs(params_);
//     if (! _previousParams)
//       return this;
    
//     if (_show && !_show->value())
//       return this;

//     VertexLine3D* that = static_cast<VertexLine3D*>(element);
//     double d=that->estimate().distance();
//     double azimuth=Line3D::azimuth(that->estimate().normal());
//     double elevation=Line3D::elevation(that->estimate().normal());
//     // std::cerr << "D=" << d << std::endl;
//     // std::cerr << "azimuth=" << azimuth << std::endl;
//     // std::cerr << "elevation=" << azimuth << std::endl;
//     glColor3f(0.25,0.25,0.4);
//     glPushMatrix();
//     glRotatef(RAD2DEG(azimuth),0.,0.,1.);
//     glRotatef(RAD2DEG(elevation),0.,-1.,0.);
//     glTranslatef(d,0.,0.);
    
//     if (_planeWidth && _planeHeight){
//       glBegin(GL_QUADS);
//       glNormal3f(-1,0,0);
//       glVertex3f(0,-_planeWidth->value(), -_planeHeight->value());
//       glVertex3f(0, _planeWidth->value(), -_planeHeight->value());
//       glVertex3f(0, _planeWidth->value(),  _planeHeight->value());
//       glVertex3f(0,-_planeWidth->value(),  _planeHeight->value());
//       glEnd();
//     }

//     glPopMatrix();
//     return this;
//   }
// #endif

}

 
