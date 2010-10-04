//      -*- Mode: c++ -*-

/** @file EventClass.h
@brief header file for EventClass.cxx
@author Eric Charles

$Header: /nfs/slac/g/glast/ground/cvs/evtUtils/evtUtils/EventClass.h,v 1.3 2010/06/29 22:31:21 echarles Exp $
*/


#ifndef EventUtils_EventClass_h
#define EventUtils_EventClass_h

#include <Rtypes.h>
#include <string>
#include <map>
#include <list>

class TTree;

/** @class EventClass
@brief Keeps track of all the event class maps

@author Eric Charles

*/

namespace evtUtils {

  class EventMap;

  class EventClass {
    
  public:
    
    static EventClass* loadFromXml(const std::string& fileName);
    
    static bool writeToHtml(EventClass& evtClass, 
			    std::ostream& os);

    static void StripLineBreaks(std::string& fromString);

  public:
    
    EventClass()
      :m_cachedTree(0){
    }
    
    EventClass(const std::string& version)
      :m_version(version),
       m_cachedTree(0){
    }
  
    virtual ~EventClass();
  
    // Utility methods  
    EventMap* addEventMap(const std::string& mapName, const std::string& altName);
    
    bool addAliasesToTTree(TTree& tree);
    
    bool addShortBranchesToTTree(TTree& tree);
    
    bool addFullBranchesToTTree(TTree& tree);

    bool initializeShortCuts(TTree& tree);
    
    bool initializeFullCuts(TTree& tree);
    
    bool fillShortCutMaps( );
    
    bool fillFullCutMaps( );
    
    EventMap* getEventMapByName(const std::string& name);

    void getEvtMapNames(std::list<std::string>& names);
    
    UInt_t* getShortMapPtr(const std::string& name);

    UInt_t* getFullMapPtr(const std::string& name);

    // accesss
    const std::string& getVersion() const { return m_version; }
    const TTree* getCachedTree() const { return m_cachedTree; }
    
  private:
    
    std::string                            m_version;    //!
    std::map<std::string,EventMap*>        m_evtMap;     //!
    TTree*                                 m_cachedTree; //!

    //ClassDef(EventClass,0) // Keeps track of a set of maps of cuts
    
  };

}

#endif
