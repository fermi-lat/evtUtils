# -*- python -*-
# $Id: SConscript,v 1.8 2010/06/29 02:40:25 echarles Exp $
# Authors: Eric Charles <echarles@slac.stanford.edu>
# Version: evtUtils-00-01-03
Import('baseEnv')
Import('listFiles')
Import('packages')
progEnv = baseEnv.Clone()
libEnv = baseEnv.Clone()

libEnv.Tool('evtUtilsLib', depsOnly = 1)
evtUtilsRootcint = libEnv.Rootcint('evtUtils/evtUtils_rootcint',                                   
                                   ['evtUtils/EventCategory.h',
                                    'evtUtils/EventMap.h',
                                    'evtUtils/EventClass.h',
                                    'evtUtils/LinkDef.h'],
                                   includes = [''])
libEnv['rootcint_node'] = evtUtilsRootcint

evtUtils = libEnv.SharedLibrary('evtUtils', listFiles(['src/*.cxx'])+['evtUtils/evtUtils_rootcint.cxx'])
progEnv.Tool('evtUtilsLib')

evtUtilsApp_MakeEventClass = progEnv.Program('MakeEventClass', ['apps/MakeEventClass.cxx'])
evtUtilsApp_MakeEventClassHtml = progEnv.Program('MakeEventClassHtml', ['apps/MakeEventClassHtml.cxx'])

progEnv.Tool('registerTargets',
             package = 'evtUtils',
             rootcintSharedCxts = [[evtUtils, libEnv]], 
             testAppsCxts = [evtUtilsApp_MakeEventClass,progEnv],
             includes = listFiles(['evtUtils/*.h']))
