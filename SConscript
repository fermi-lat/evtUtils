# -*- python -*-
# $Id: SConscript,v 1.23 2012/08/20 18:57:51 jrb Exp $
# Authors: Eric Charles <echarles@slac.stanford.edu>
# Version: evtUtils-00-02-01
Import('baseEnv')
Import('listFiles')
Import('packages')
progEnv = baseEnv.Clone()
libEnv = baseEnv.Clone()

libEnv.Tool('evtUtilsLib', depsOnly = 1)

evtUtilsLib = libEnv.SharedLibrary('evtUtils', listFiles(['src/*.cxx']))
progEnv.Tool('evtUtilsLib')

evtUtilsApp_MakeEventClass = progEnv.Program('MakeEventClass', ['apps/MakeEventClass.cxx'])
evtUtilsApp_MakeEventClassPyDict = progEnv.Program('MakeEventClassPyDict', ['apps/MakeEventClassPyDict.cxx'])
evtUtilsApp_MakeEventClassHtml = progEnv.Program('MakeEventClassHtml', ['apps/MakeEventClassHtml.cxx'])

progEnv.Tool('registerTargets',
             package = 'evtUtils',
             libraryCxts = [[evtUtilsLib, libEnv]],
             xml = listFiles(['xml/*.xml']),
             testAppsCxts = [evtUtilsApp_MakeEventClass,evtUtilsApp_MakeEventClassPyDict,evtUtilsApp_MakeEventClassHtml,progEnv],
             includes = listFiles(['evtUtils/*.h']))
