// -*- Mode: c++ -*-
/** @file LinkDef.h
    @brief for rootcint
 $Header: /nfs/slac/g/glast/ground/cvs/evtUtils/evtUtils/LinkDef.h,v 1.1.1.1 2010/06/14 23:33:06 echarles Exp $

*/
#ifdef __CINT__


#pragma link off all globals;
#pragma link off all classes;
#pragma link off all functions;

// in TMine/util
#pragma link C++ namespace evtUtils;
#pragma link C++ class evtUtils::AliasDict;
#pragma link C++ class evtUtils::EventCategory;
#pragma link C++ class evtUtils::EventMap;
#pragma link C++ class evtUtils::EventClass;

#endif

